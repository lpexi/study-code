#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
  #include <windows.h>
  void sleep_ms(int ms) { Sleep(ms); }
#else
  #include <unistd.h>
  void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

// Bildschirm loeschen + Cursor nach oben links (ANSI)
void clear_screen() {
    printf("\033[2J\033[H");
}

// n Leerzeichen drucken (Einrueckung)
void indent(int n) {
    for (int i = 0; i < n; i++) putchar(' ');
}

// Frame 0 deiner Turtle
void draw_turtle_frame0(int x) {
    indent(x); printf("                                ___-------___\n");
    indent(x); printf("                            _-~~             ~~-_\n");
    indent(x); printf("                        _-~                    /~-_\n");
    indent(x); printf("        /^\\__/^\\         /~  \\\\                   /    \\\n");
    indent(x); printf("        /|  O|| O|        /      \\\\_______________/        \\\n");
    indent(x); printf("        | |___||__|      /       /                \\\\          \\\n");
    indent(x); printf("        |          \\\\    /      /                    \\\\          \\\n");
    indent(x); printf("        |   (_______) /______/                        \\\\_________ \\\n");
    indent(x); printf("        |         / /         \\\\                      /            \\\n");
    indent(x); printf("        \\\\         \\\\^\\\\         \\\\                  /               \\\\     /\n");
    indent(x); printf("         \\\\         ||           \\\\______________/      _-_       //\\\\__//\n");
    indent(x); printf("             \\\\       ||------_-~~-_ ------------- \\\\ --/~   ~\\\\    || __/\n");
    indent(x); printf("             ~-----||====/~     |==================|       |/~~~~~\n");
    indent(x); printf("                 (_(__/  ./     /                    \\\\_\\\\      \\\\. \n");
    indent(x); printf("                     (_(___/                         \\\\_____)_)\n");
}

// Frame 1: minimal veraendert (sieht aus wie “laufender Schritt”)
void draw_turtle_frame1(int x) {
    indent(x); printf("                                ___-------___\n");
    indent(x); printf("                            _-~~             ~~-_\n");
    indent(x); printf("                        _-~                    /~-_\n");
    indent(x); printf("        /^\\__/^\\         /~  \\\\                   /    \\\n");
    indent(x); printf("        /|  O|| O|        /      \\\\_______________/        \\\n");
    indent(x); printf("        | |___||__|      /       /                \\\\          \\\n");
    indent(x); printf("        |          \\\\    /      /                    \\\\          \\\n");
    indent(x); printf("        |   (_______) /______/                        \\\\_________ \\\n");
    indent(x); printf("        |         / /         \\\\                      /            \\\n");
    indent(x); printf("        \\\\         \\\\^\\\\         \\\\                  /               \\\\   _/\n");
    indent(x); printf("         \\\\         ||           \\\\______________/      _-_       //\\\\_//\n");
    indent(x); printf("             \\\\       ||------_-~~-_ ------------- \\\\ --/~   ~\\\\    ||\n");
    indent(x); printf("             ~-----||====/~     |==================|       |/~~~~~\n");
    indent(x); printf("                 (_(__/  ./     /                    \\\\_\\\\      \\\\. \n");
    indent(x); printf("                     (_(___/                         \\\\_____)_)\n");
}

int main() {
    // Puffer aus, damit Animation sofort erscheint
    setvbuf(stdout, NULL, _IONBF, 0);

    int x = 0;
    int dir = 1;

    // Animation: laeuft hin und her
    for (int t = 0; t < 400; t++) {
        clear_screen();

        if (t % 2 == 0) draw_turtle_frame0(x);
        else            draw_turtle_frame1(x);

        // Position updaten
        x += dir;

        // Grenzen (Terminalbreite grob abgeschaetzt)
        if (x > 30) dir = -1;
        if (x < 0)  dir = 1;

        sleep_ms(60);
    }

    // Am Ende Cursor sichtbar/normal
    printf("\n");
    return 0;
}
