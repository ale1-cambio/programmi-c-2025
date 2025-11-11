#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
#endif

void drawCube(float angleX, float angleY, float angleZ, float scale) {
    char buffer[25][80];
    float zbuffer[25][80];
    
    // Clear buffers
    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 80; j++) {
            buffer[i][j] = ' ';
            zbuffer[i][j] = 0;
        }
    }
    
    // Cube vertices
    float vertices[8][3] = {
        {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
        {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}
    };
    
    // Cube edges
    int edges[12][2] = {
        {0,1}, {1,2}, {2,3}, {3,0},  // Back face
        {4,5}, {5,6}, {6,7}, {7,4},  // Front face
        {0,4}, {1,5}, {2,6}, {3,7}   // Connecting edges
    };
    
    // Rotation matrices
    float cosX = cos(angleX), sinX = sin(angleX);
    float cosY = cos(angleY), sinY = sin(angleY);
    float cosZ = cos(angleZ), sinZ = sin(angleZ);
    
    // Draw each edge
    for(int e = 0; e < 12; e++) {
        int v1 = edges[e][0];
        int v2 = edges[e][1];
        
        // Interpolate between vertices
        for(float t = 0; t <= 1; t += 0.01) {
            float x = vertices[v1][0] + t * (vertices[v2][0] - vertices[v1][0]);
            float y = vertices[v1][1] + t * (vertices[v2][1] - vertices[v1][1]);
            float z = vertices[v1][2] + t * (vertices[v2][2] - vertices[v1][2]);
            
            // Apply rotations
            // Rotate around X
            float y1 = y * cosX - z * sinX;
            float z1 = y * sinX + z * cosX;
            y = y1; z = z1;
            
            // Rotate around Y
            float x1 = x * cosY + z * sinY;
            z1 = -x * sinY + z * cosY;
            x = x1; z = z1;
            
            // Rotate around Z
            x1 = x * cosZ - y * sinZ;
            y1 = x * sinZ + y * cosZ;
            x = x1; y = y1;
            
            // Scale
            x *= scale;
            y *= scale;
            z *= scale;
            
            // Project to 2D
            float K = 20;
            float depth = 1 / (z + 5);
            int screenX = (int)(40 + K * depth * x);
            int screenY = (int)(12 + K * depth * y * 0.5);
            
            // Draw if in bounds
            if(screenY >= 0 && screenY < 25 && screenX >= 0 && screenX < 80) {
                if(depth > zbuffer[screenY][screenX]) {
                    zbuffer[screenY][screenX] = depth;
                    buffer[screenY][screenX] = ".:!*oe&#%@"[(int)(depth * 8)];
                }
            }
        }
    }
    
    // Print buffer
    for(int i = 0; i < 25; i++) {
        for(int j = 0; j < 80; j++) {
            putchar(buffer[i][j]);
        }
        putchar('\n');
    }
}

void printMenu() {
    printf("\n=== INTERACTIVE 3D CUBE ===\n");
    printf("Commands:\n");
    printf("  1 - Rotate X+ (pitch up)      2 - Rotate X- (pitch down)\n");
    printf("  3 - Rotate Y+ (turn right)    4 - Rotate Y- (turn left)\n");
    printf("  5 - Rotate Z+ (roll right)    6 - Rotate Z- (roll left)\n");
    printf("  7 - Zoom in (+)               8 - Zoom out (-)\n");
    printf("  9 - Auto-rotate mode          0 - Reset view\n");
    printf("  q - Quit\n");
    printf("\nEnter command: ");
}

int main() {
    float angleX = 0.5, angleY = 0.5, angleZ = 0;
    float scale = 2.0;
    char command;
    int running = 1;
    int autoRotateFrames = 0;
    
    printf("=== INTERACTIVE 3D CUBE VIEWER ===\n");
    printf("Press Enter to start...\n");
    getchar();
    
    while(running) {
        system(CLEAR_SCREEN);
        
        drawCube(angleX, angleY, angleZ, scale);
        
        printf("\nCurrent state: X=%.2f Y=%.2f Z=%.2f Scale=%.1f\n", 
               angleX, angleY, angleZ, scale);
        
        printMenu();
        
        scanf(" %c", &command);
        
        switch(command) {
            case '1': angleX += 0.3; break;
            case '2': angleX -= 0.3; break;
            case '3': angleY += 0.3; break;
            case '4': angleY -= 0.3; break;
            case '5': angleZ += 0.3; break;
            case '6': angleZ -= 0.3; break;
            case '7': scale += 0.5; if(scale > 10) scale = 10; break;
            case '8': scale -= 0.5; if(scale < 0.5) scale = 0.5; break;
            case '9': 
                autoRotateFrames = 50;
                printf("\nAuto-rotating...\n");
                for(int i = 0; i < autoRotateFrames; i++) {
                    system(CLEAR_SCREEN);
                    angleX += 0.05;
                    angleY += 0.08;
                    angleZ += 0.03;
                    drawCube(angleX, angleY, angleZ, scale);
                    printf("\nAuto-rotate frame %d/%d\n", i+1, autoRotateFrames);
                    #ifdef _WIN32
                        Sleep(50);
                    #else
                        usleep(50000);
                    #endif
                }
                printf("Press Enter to continue...");
                getchar();
                break;
            case '0':
                angleX = 0.5;
                angleY = 0.5;
                angleZ = 0;
                scale = 2.0;
                printf("\nView reset!\n");
                break;
            case 'q':
            case 'Q':
                running = 0;
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid command!\n");
                break;
        }
        
        if(running && command != '9') {
            printf("Press Enter to continue...");
            getchar();
        }
    }
    
    return 0;
}