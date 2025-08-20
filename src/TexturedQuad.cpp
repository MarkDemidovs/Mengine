#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "TexturedQuad.h"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>

// Vertex + UV
static float vertices[] = {
    // pos         // uv
     0.5f,  0.5f, 0.0f,   1.0f, 1.0f,
     0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
    -0.5f,  0.5f, 0.0f,   0.0f, 1.0f
};

static unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

static const char* vertexShaderSrc = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec2 aUV;

    out vec2 vUV;
    uniform mat4 uModel;

    void main() {
        gl_Position = uModel * vec4(aPos, 1.0);
        vUV = aUV;
    }
)";

static const char* fragmentShaderSrc = R"(
    #version 330 core
    in vec2 vUV;
    out vec4 FragColor;

    uniform sampler2D uTex0;

    void main() {
        FragColor = texture(uTex0, vUV);
    }
)";

TexturedQuad::TexturedQuad(const std::string& texturePath) {
    // VAO / VBO / EBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Shaders
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSrc, nullptr);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSrc, nullptr);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);  

    int w, h, channels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(texturePath.c_str(), &w, &h, &channels, 0);
    if (data) {
        GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
        if (channels == 1) format = GL_RED;

        if (channels == 3) glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "Failed to load texture: " << texturePath << std::endl;
    }
    stbi_image_free(data);

    glUseProgram(shaderProgram);
    int texLoc = glGetUniformLocation(shaderProgram, "uTex0");
    glUniform1i(texLoc, 0); // texture unit 0

    modelLoc = glGetUniformLocation(shaderProgram, "uModel");
}

TexturedQuad::~TexturedQuad() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
    glDeleteTextures(1, &textureID);
}

void TexturedQuad::draw(const glm::mat4& model) {
    glUseProgram(shaderProgram);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
