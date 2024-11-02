#include "gui/Gui.hpp"

#include <GLFW/glfw3.h>

#include <cstdio>
#include <stdexcept>

#include "DroidSans_ttf.cpp"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "gui/HandleIntegerFunctions.hpp"
#include "gui/HandleNaturalFunctions.hpp"
#include "gui/HandlePolynomialFunctions.hpp"
#include "gui/HandleRationalFunctions.hpp"
#include "imgui.h"

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

static bool showMainMenu = true;
static bool showNaturalFuncMenu = false;
static bool showIntegerFuncMenu = false;
static bool showRationalFuncMenu = false;
static bool showPolynomialFuncMenu = false;

void Gui::run() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) throw std::runtime_error("Failed to initialize GLFW");

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
    if (window == nullptr) throw std::runtime_error("Failed to create window");
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable Gamepad Controls

    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);  // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();

    // io.Fonts->AddFontFromFileTTF("DroidSans.ttf", 16);
    // Load font with Cyrillic characters support
    // io.Fonts->AddFontFromFileTTF("DroidSans.ttf", 16.0f, NULL, io.Fonts->GetGlyphRangesCyrillic());
    io.Fonts->AddFontFromMemoryCompressedTTF(DroidSans_compressed_data, DroidSans_compressed_size, 16.f, NULL, io.Fonts->GetGlyphRangesCyrillic());

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();

        if (showMainMenu) ShowMainMenu();
        if (showNaturalFuncMenu) HandleNaturalFunctions::showMenu(&showNaturalFuncMenu);
        if (showIntegerFuncMenu) HandleIntegerFunctions::showMenu(&showIntegerFuncMenu);
        if (showRationalFuncMenu) HandleRationalFunctions::showMenu(&showRationalFuncMenu);
        if (showPolynomialFuncMenu) HandlePolynomialFunctions::showMenu(&showPolynomialFuncMenu);

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    return;
}

void Gui::ShowMainMenu() {
    ImGui::Begin("Main Menu");

    if (ImGui::Button("Натуральные числа с нулем (N)")) {
        showNaturalFuncMenu = !showNaturalFuncMenu;
    }

    if (ImGui::Button("Целые числа (Z)")) {
        showIntegerFuncMenu = !showIntegerFuncMenu;
    }

    if (ImGui::Button("Рациональные числа (Q)")) {
        showRationalFuncMenu = !showRationalFuncMenu;
    }

    if (ImGui::Button("Многочлены (P)")) {
        showPolynomialFuncMenu = !showPolynomialFuncMenu;
    }

    if (ImGui::Button("Выход")) {
        glfwSetWindowShouldClose(glfwGetCurrentContext(), GLFW_TRUE);
    }

    ImGui::End();
}