#include "graphics.h"
#include "include/glad/glad.h"
#include <iostream>

unsigned int pointShaderProg;
unsigned int pointVAO;
unsigned int pointVBO; 
unsigned int lineVAO;
unsigned int lineVBO; 
std::array<Coord, 5000> pointSamples;
int numPoints;
bool curveBegan = false;

unsigned int compileShader(unsigned int type, const char* source) {
    unsigned int shader;
    shader = glCreateShader(type);    // create shader
    glShaderSource(shader, 1, &source, NULL);     // specify source of shader
    glCompileShader(shader);
    // error checking
    int success; char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Shader Error: " << infoLog << std::endl;
    }
    return shader;
}

unsigned int linkProgram(unsigned int VShader, unsigned int FShader) {
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, VShader);
    glAttachShader(shaderProgram, FShader);
    glLinkProgram(shaderProgram);

    // error checking
    int success; char infoLog[512];
    glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Shader Error: " << infoLog << std::endl;
    }
    return shaderProgram;
}

const char* pointVShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec2 aPos;\n"
"void main() {\n"
"    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);\n"
"    gl_PointSize = 3;\n"
"}";

const char* pointFShaderSource = 
"#version 330 core\n"
"uniform vec3 color = vec3(1f, 1f, 1f);"
"out vec4 fragColor;\n"
"void main() {\n"
"    fragColor = vec4(color.x, color.y, color.z, 1.0f);\n"
"}\n";

void initGraphics() {
    glEnable(GL_PROGRAM_POINT_SIZE); 

    // shaders for points
    unsigned int pointVShader = compileShader(GL_VERTEX_SHADER, pointVShaderSource);
    unsigned int pointFShader = compileShader(GL_FRAGMENT_SHADER, pointFShaderSource);
    pointShaderProg = linkProgram(pointVShader, pointFShader);
    glDeleteShader(pointVShader);
    glDeleteShader(pointFShader);
    
    // VAO and VBO stuff for point
    glGenVertexArrays(1, &pointVAO);    // create vertex array object
    glBindVertexArray(pointVAO);
    
    glGenBuffers(1, &pointVBO);       // create vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, pointVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Coord), NULL, GL_STATIC_DRAW);       // send data to GPU

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)NULL);
    glEnableVertexAttribArray(0);

    // VAO and VBO stuff for line
    glGenVertexArrays(1, &lineVAO);
    glBindVertexArray(lineVAO);

    glGenBuffers(1, &lineVBO);
    glBindBuffer(GL_ARRAY_BUFFER, lineVBO);
    glBufferData(GL_ARRAY_BUFFER, 2500 * sizeof(Line), NULL, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)NULL);
    glEnableVertexAttribArray(0);

    numPoints = 0;
}

void drawPoint(Coord point) {
    if (curveBegan) {
        pointSamples[numPoints++] = point;
        return;
    }
    glBindBuffer(GL_ARRAY_BUFFER, pointVBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Coord), &point);
    glBindVertexArray(pointVAO);
    glUseProgram(pointShaderProg);
    glDrawArrays(GL_POINTS, 0, 1);
}

void drawLine(Line line) {
    glBindBuffer(GL_ARRAY_BUFFER, lineVBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Line), &line);
    glBindVertexArray(lineVAO);
    glUseProgram(pointShaderProg);
    glDrawArrays(GL_LINES, 0, 2);
}

void beginCurve() {
    numPoints = 0;
    curveBegan = true;
}

void endCurve() {
    glBindBuffer(GL_ARRAY_BUFFER, lineVBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, numPoints* sizeof(Coord), pointSamples.data());
    glBindVertexArray(lineVAO);
    glUseProgram(pointShaderProg);
    glDrawArrays(GL_LINE_STRIP, 0, numPoints);
    curveBegan = false;
}

inline void drawCircle(Coord centre, float radius) {
    centre = {0, 0};
    radius = 0;
}

void setColor(unsigned char r, unsigned char g, unsigned char b) {
    GLint location = glGetUniformLocation(pointShaderProg, "color");
    if (location != -1) {
        glUniform3f(location, (float) r/255, (float) g/255, (float) b/255);
    }
}