#ifdef _MSC_VER
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#define LITE_GFX_IMPLEMENTATION
#include <litegfx.h>
#include <glfw3.h>
#include <iostream>

using namespace std;

int main() {
	// Inicializamos GLFW
	if (!glfwInit()) {
		cout << "Error: No se ha podido inicializar GLFW" << endl;
		return -1;
	}
	atexit(glfwTerminate);

	// Creamos la ventana
	glfwWindowHint(GLFW_RESIZABLE, false);
	GLFWwindow* window = glfwCreateWindow(800, 600, "Programacion 2D", nullptr, nullptr);
	if (!window) {
		cout << "Error: No se ha podido crear la ventana" << endl;
		return -1;
	}

	// Activamos contexto de OpenGL
	glfwMakeContextCurrent(window);

	// Inicializamos LiteGFX
	lgfx_setup2d(800, 600);

	// Bucle principal
	float x = 0;
	double xposSquare = 0;
	double yposSquare = 0;

	double xposCircle = 0;
	double yposCircle = 0;
	float circeDistance = 50;

	double lastTime = glfwGetTime();
	while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE)) {
		// Actualizamos delta
		float deltaTime = static_cast<float>(glfwGetTime() - lastTime);
		lastTime = glfwGetTime();

		// Actualizamos tamaño de ventana
		int screenWidth, screenHeight;
		glfwGetWindowSize(window, &screenWidth, &screenHeight);
		lgfx_setviewport(0, 0, screenWidth, screenHeight);

		// Actualizacion de logica del programa
		glfwGetCursorPos(window, &xposSquare, &yposSquare);
		xposCircle = xposSquare - circeDistance;
		yposCircle = yposSquare - circeDistance;

		// Pintado
		lgfx_clearcolorbuffer(0, 0, 0);
		lgfx_setcolor(1, 0, 0, 1);
		lgfx_drawrect(screenWidth/2 -25, screenHeight/2 - 25, 50, 50);

		lgfx_setcolor(1, 1, 1, 1);
		lgfx_drawrect(xposSquare - 25, yposSquare - 25, 50, 50);

		lgfx_setcolor(1, 1, 0, 1);
		lgfx_drawoval(xposCircle - 10, yposCircle - 10, 20, 20);


		// Actualizamos ventana y eventos
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    return 0;
}
