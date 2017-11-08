#ifdef _MSC_VER
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") //hide the console
#endif // _MSC_VER

#define LITE_GFX_IMPLEMENTATION
#include <litegfx.h>
#include <glfw3.h>
#include <iostream>

using namespace std;

int main() {
    
	if (!glfwInit()) {
		cout << "Error: GLFW unable to initialize!" << endl;
		return -1;
	}
	atexit(glfwTerminate); //At exit call glfwTerminate()

	//create the window
	//glfwWindowHint(GLFW_RESIZABLE, false); //Set window to Unsizable

	GLFWwindow* window = glfwCreateWindow(800, 600, "2D Programming", nullptr, nullptr);

	if (!window) {
		cout << "Error: Unable to create window!" << endl;
		return -1;
	}

	//activate current context of OpenGL
	glfwMakeContextCurrent(window);
	
	//Init LiteGFX

	lgfx_setup2d(800, 600);

	//principal loop
	float x = 0;
	double lastTime = glfwGetTime();
	while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE)) {
		//Update DeltaTime
		float deltaTime = static_cast<float>(glfwGetTime() - lastTime);
		lastTime = glfwGetTime();

		//Update Window Size

		int screenWidth, screenHeight;
		glfwGetWindowSize(window, &screenWidth, &screenHeight);
		lgfx_setviewport(0, 0, screenWidth, screenHeight);
		//Update
		x += 128 * deltaTime;

		//Render
		lgfx_clearcolorbuffer(0, 0, 0.5f);
		lgfx_setcolor(1, 0, 0, 1);
		lgfx_drawrect(x, screenHeight/2 - 50, 100, 100);
			
		//Updating window and events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}




	//Exit
	return 0;
}

