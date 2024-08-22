#include "pretty_print.hpp"

int main() {
    // Demonstrating Text Colors
    PRINT(RED, "This is red text");
    PRINT(GREEN, "This is green text");
    PRINT(YELLOW, "This is yellow text");
    PRINT(BLUE, "This is blue text");
    PRINT(PINK, "This is pink (magenta) text");
    PRINT(CYAN, "This is cyan text");
    PRINT(WHITE, "This is white text");
    PRINT(L_RED, "This is bright red text");
    PRINT(L_GREEN, "This is bright green text");
    PRINT(L_YELLOW, "This is bright yellow text");
    PRINT(L_BLUE, "This is bright blue text");
    PRINT(L_PINK, "This is bright pink text");
    PRINT(L_CYAN, "This is bright cyan text");
    PRINT(L_WHITE, "This is bright white text");

    // Demonstrating Background Colors
    PRINT(BG_RED, "This is text with a red background");
    PRINT(BG_GREEN, "This is text with a green background");
    PRINT(BG_YELLOW, "This is text with a yellow background");
    PRINT(BG_BLUE, "This is text with a blue background");
    PRINT(BG_PINK, "This is text with a pink (magenta) background");
    PRINT(BG_CYAN, "This is text with a cyan background");
    PRINT(BG_WHITE, "This is text with a white background");
    PRINT(BG_LRED, "This is text with a bright red background");
    PRINT(BG_LGREEN, "This is text with a bright green background");
    PRINT(BG_LYELLOW, "This is text with a bright yellow background");
    PRINT(BG_LBLUE, "This is text with a bright blue background");
    PRINT(BG_LPINK, "This is text with a bright pink background");
    PRINT(BG_LCYAN, "This is text with a bright cyan background");
    PRINT(BG_LWHITE, "This is text with a bright white background");

    // Demonstrating Text Styles
    PRINT(BOLD, "This is bold text");
    PRINT(UNDERLINE, "This is underlined text");
    PRINT(BLINK, "This is blinking text");
    PRINT(REVERSE, "This is reversed text (foreground and background colors swapped)");
    PRINT(HIDDEN, "This is hidden text (you shouldn't see this)");

    // Combining Colors and Styles
    PRINT(BOLD RED, "Bold red text");
    PRINT(UNDERLINE BLUE, "Underlined blue text");
    PRINT(BLINK GREEN, "Blinking green text");
    PRINT(REVERSE YELLOW, "Reversed yellow text with swapped colors");
    PRINT(BG_CYAN PINK, "Pink text on a cyan background");
}