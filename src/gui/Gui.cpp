#include "gui/Gui.hpp"

#include <GLFW/glfw3.h>

#include <cstdio>
#include <stdexcept>

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "gui/NaturalFunctions.hpp"
#include "imgui.h"

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

enum class MenuState {
    MainMenu,
    NaturalFuncMenu,
    IntegerFuncMenu,
    RationalFuncMenu,
    PolynomialFuncMenu,
    CompareNaturalNumbers,
    CheckForZero,
    AddOneToNatural,
    AddNaturalNumbers,
    // Add other states as needed
};

static MenuState currentMenu = MenuState::MainMenu;

void Gui::ShowNaturalCompareMenu() {
    ImGui::Begin("Compare Natural Numbers");

    ImGui::Text("This is a placeholder for the Compare Natural Numbers menu");

    ImGui::End();
}

void Gui::ShowNaturalCheckForZeroMenu() {
    ImGui::Begin("Check for Zero");

    ImGui::Text("This is a placeholder for the Check for Zero menu");

    ImGui::End();
}

void Gui::ShowNaturalAddOneMenu() {
    ImGui::Begin("Add 1 to Natural Number");

    ImGui::Text("This is a placeholder for the Add 1 to Natural Number menu");

    ImGui::End();
}

void Gui::ShowNaturalAddMenu() {
    ImGui::Begin("Add Natural Numbers");

    ImGui::Text("This is a placeholder for the Add Natural Numbers menu");

    ImGui::End();
}

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

    HandleNaturalFunctions handleNaturalFunctions;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        switch (currentMenu) {
            case MenuState::MainMenu:
                ShowMainMenu();
                break;
            case MenuState::NaturalFuncMenu:
                handleNaturalFunctions.ShowNaturalFuncMenu();
                break;
            case MenuState::IntegerFuncMenu:
                ShowIntegerFuncMenu();
                break;
            case MenuState::RationalFuncMenu:
                ShowRationalFuncMenu();
                break;
            case MenuState::PolynomialFuncMenu:
                ShowPolynomialFuncMenu();
                break;
            case MenuState::CompareNaturalNumbers:
                ShowNaturalCompareMenu();
                break;
            case MenuState::CheckForZero:
                ShowNaturalCheckForZeroMenu();
                break;
            case MenuState::AddOneToNatural:
                ShowNaturalAddOneMenu();
                break;
            case MenuState::AddNaturalNumbers:
                ShowNaturalAddMenu();
                break;
                // Add other cases as needed
        }

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

// Forward declarations of functions to handle specific actions
void HandleNaturalFunc(int choice) {};
void HandleIntegerFunc(int choice) {};
void HandleRationalFunc(int choice) {};
void HandlePolynomialFunc(int choice) {};

void Gui::ShowMainMenu() {
    ImGui::Begin("Main Menu");

    if (ImGui::CollapsingHeader("Natural Numbers (N)")) {
        if (ImGui::Button("Compare Natural Numbers")) {
            currentMenu = MenuState::CompareNaturalNumbers;
        }
        if (ImGui::Button("Check for Zero")) {
            currentMenu = MenuState::CheckForZero;
        }
        if (ImGui::Button("Add 1 to Natural Number")) {
            currentMenu = MenuState::AddOneToNatural;
        }
        if (ImGui::Button("Add Natural Numbers")) {
            currentMenu = MenuState::AddNaturalNumbers;
        }
    }

    if (ImGui::CollapsingHeader("Integers (Z)")) {
        if (ImGui::Button("Absolute Value")) {
            HandleIntegerFunc(1);
        }
        if (ImGui::Button("Determine Sign")) {
            HandleIntegerFunc(2);
        }
        if (ImGui::Button("Multiply by -1")) {
            HandleIntegerFunc(3);
        }
        if (ImGui::Button("Convert Natural to Integer")) {
            HandleIntegerFunc(4);
        }
        if (ImGui::Button("Convert Non-Negative Integer to Natural")) {
            HandleIntegerFunc(5);
        }
        if (ImGui::Button("Add Integers")) {
            HandleIntegerFunc(6);
        }
        if (ImGui::Button("Subtract Integers")) {
            HandleIntegerFunc(7);
        }
        if (ImGui::Button("Multiply Integers")) {
            HandleIntegerFunc(8);
        }
        if (ImGui::Button("Divide Integers")) {
            HandleIntegerFunc(9);
        }
    }

    if (ImGui::CollapsingHeader("Rational Numbers (R)")) {
        if (ImGui::Button("Reduce Fraction")) {
            HandleRationalFunc(1);
        }
        if (ImGui::Button("Check if Fraction is Integer")) {
            HandleRationalFunc(2);
        }
        if (ImGui::Button("Convert Integer to Fraction")) {
            HandleRationalFunc(3);
        }
        if (ImGui::Button("Convert Fraction to Integer")) {
            HandleRationalFunc(4);
        }
        if (ImGui::Button("Add Fractions")) {
            HandleRationalFunc(5);
        }
        if (ImGui::Button("Subtract Fractions")) {
            HandleRationalFunc(6);
        }
        if (ImGui::Button("Multiply Fractions")) {
            HandleRationalFunc(7);
        }
        if (ImGui::Button("Divide Fractions")) {
            HandleRationalFunc(8);
        }
    }

    if (ImGui::CollapsingHeader("Polynomials (P)")) {
        if (ImGui::Button("Add Polynomials")) {
            HandlePolynomialFunc(1);
        }
        if (ImGui::Button("Subtract Polynomials")) {
            HandlePolynomialFunc(2);
        }
        if (ImGui::Button("Multiply Polynomial by Rational")) {
            HandlePolynomialFunc(3);
        }
        if (ImGui::Button("Multiply Polynomial by x^k")) {
            HandlePolynomialFunc(4);
        }
        if (ImGui::Button("Get Leading Coefficient")) {
            HandlePolynomialFunc(5);
        }
        if (ImGui::Button("Get Degree of Polynomial")) {
            HandlePolynomialFunc(6);
        }
        if (ImGui::Button("Factor Polynomial")) {
            HandlePolynomialFunc(7);
        }
        if (ImGui::Button("Multiply Polynomials")) {
            HandlePolynomialFunc(8);
        }
        if (ImGui::Button("Divide Polynomials")) {
            HandlePolynomialFunc(9);
        }
        if (ImGui::Button("Compute Remainder of Polynomial Division")) {
            HandlePolynomialFunc(10);
        }
        if (ImGui::Button("Compute GCD of Polynomials")) {
            HandlePolynomialFunc(11);
        }
        if (ImGui::Button("Compute Derivative of Polynomial")) {
            HandlePolynomialFunc(12);
        }
        if (ImGui::Button("Simplify Polynomial")) {
            HandlePolynomialFunc(13);
        }
    }

    if (ImGui::Button("Exit")) {
        glfwSetWindowShouldClose(glfwGetCurrentContext(), GLFW_TRUE);
    }

    ImGui::End();
}

void Gui::ShowNaturalFuncMenu() {
    ImGui::Begin("Natural Functions Menu");

    if (ImGui::Button("1. Compare Natural Numbers")) {
        currentMenu = MenuState::CompareNaturalNumbers;
    }
    if (ImGui::Button("2. Check for Zero")) {
        currentMenu = MenuState::CheckForZero;
    }
    if (ImGui::Button("3. Add 1 to Natural Number")) {
        currentMenu = MenuState::AddOneToNatural;
    }
    if (ImGui::Button("4. Add Natural Numbers")) {
        currentMenu = MenuState::AddNaturalNumbers;
    }
    if (ImGui::Button("Back")) {
        currentMenu = MenuState::MainMenu;
    }

    ImGui::End();
}

void Gui::ShowIntegerFuncMenu() {
    ImGui::Begin("Integer Functions Menu");

    if (ImGui::Button("1. Absolute Value")) {
        HandleIntegerFunc(1);
    }
    if (ImGui::Button("2. Determine Sign")) {
        HandleIntegerFunc(2);
    }
    if (ImGui::Button("3. Multiply by -1")) {
        HandleIntegerFunc(3);
    }
    if (ImGui::Button("4. Convert Natural to Integer")) {
        HandleIntegerFunc(4);
    }
    if (ImGui::Button("5. Convert Non-Negative Integer to Natural")) {
        HandleIntegerFunc(5);
    }
    if (ImGui::Button("6. Add Integers")) {
        HandleIntegerFunc(6);
    }
    if (ImGui::Button("7. Subtract Integers")) {
        HandleIntegerFunc(7);
    }
    if (ImGui::Button("8. Multiply Integers")) {
        HandleIntegerFunc(8);
    }
    if (ImGui::Button("9. Divide Integers")) {
        HandleIntegerFunc(9);
    }
    if (ImGui::Button("Back")) {
        currentMenu = MenuState::MainMenu;
    }

    ImGui::End();
}

void Gui::ShowRationalFuncMenu() {
    ImGui::Begin("Rational Functions Menu");

    if (ImGui::Button("1. Reduce Fraction")) {
        HandleRationalFunc(1);
    }
    if (ImGui::Button("2. Check if Fraction is Integer")) {
        HandleRationalFunc(2);
    }
    if (ImGui::Button("3. Convert Integer to Fraction")) {
        HandleRationalFunc(3);
    }
    if (ImGui::Button("4. Convert Fraction to Integer")) {
        HandleRationalFunc(4);
    }
    if (ImGui::Button("5. Add Fractions")) {
        HandleRationalFunc(5);
    }
    if (ImGui::Button("6. Subtract Fractions")) {
        HandleRationalFunc(6);
    }
    if (ImGui::Button("7. Multiply Fractions")) {
        HandleRationalFunc(7);
    }
    if (ImGui::Button("8. Divide Fractions")) {
        HandleRationalFunc(8);
    }
    if (ImGui::Button("Back")) {
        currentMenu = MenuState::MainMenu;
    }

    ImGui::End();
}

void Gui::ShowPolynomialFuncMenu() {
    ImGui::Begin("Polynomial Functions Menu");

    if (ImGui::Button("1. Add Polynomials")) {
        HandlePolynomialFunc(1);
    }
    if (ImGui::Button("2. Subtract Polynomials")) {
        HandlePolynomialFunc(2);
    }
    if (ImGui::Button("3. Multiply Polynomial by Rational")) {
        HandlePolynomialFunc(3);
    }
    if (ImGui::Button("4. Multiply Polynomial by x^k")) {
        HandlePolynomialFunc(4);
    }
    if (ImGui::Button("5. Get Leading Coefficient")) {
        HandlePolynomialFunc(5);
    }
    if (ImGui::Button("6. Get Degree of Polynomial")) {
        HandlePolynomialFunc(6);
    }
    if (ImGui::Button("7. Factor Polynomial")) {
        HandlePolynomialFunc(7);
    }
    if (ImGui::Button("8. Multiply Polynomials")) {
        HandlePolynomialFunc(8);
    }
    if (ImGui::Button("9. Divide Polynomials")) {
        HandlePolynomialFunc(9);
    }
    if (ImGui::Button("10. Compute Remainder of Polynomial Division")) {
        HandlePolynomialFunc(10);
    }
    if (ImGui::Button("11. Compute GCD of Polynomials")) {
        HandlePolynomialFunc(11);
    }
    if (ImGui::Button("12. Compute Derivative of Polynomial")) {
        HandlePolynomialFunc(12);
    }
    if (ImGui::Button("13. Simplify Polynomial")) {
        HandlePolynomialFunc(13);
    }
    if (ImGui::Button("Back")) {
        currentMenu = MenuState::MainMenu;
    }

    ImGui::End();
}
