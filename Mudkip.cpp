#include <iostream>
#include <string>
#include <windows.h> // Necesario para gotoxy y HANDLE

using namespace std;

/**
 * @brief Posiciona el cursor en la consola en las coordenadas especificadas.
 * Útil para sobrescribir la pantalla sin causar parpadeo (flickering).
 * * @param x Posición en el eje X (columnas).
 * @param y Posición en el eje Y (filas).
 */
void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

/**
 * @class MascotaAvanzada
 * @brief Simulador de Mudkip con estados visuales personalizables y físicas de vida.
 */
class MascotaAvanzada {
private:
    string nombre;
    int nivel, exp, energia, hp, hpMaximo, hambre;
    float amistad;
    
    /**
     * @enum Estado
     * @brief Define los posibles estados en los que puede encontrarse mudkip.
     */
    enum Estado { NORMAL, COMIENDO, ENTRENANDO, DURMIENDO, MUERTO };
    Estado estadoActual;

    /**
     * @brief Cada uno de los artes ASCII de mudkip.
     */
    void dibujarMudkip() {
        switch (estadoActual) {
            case NORMAL:
                cout <<"                        ..                                                                 "<< endl;
                cout <<"                       :=:.                                                                "<< endl;
                cout <<"                      .-=-.                                                                "<< endl;
                cout <<"                      .-=-:                                                                "<< endl;
                cout <<"                      .-=-:                                                                "<< endl;
                cout <<"                       :=-:.                                                               "<< endl;
                cout <<"                       .==:.                                                               "<< endl;
                cout <<"                       .-=:.                                                               "<< endl;
                cout <<"                        :=:.                                                               "<< endl;
                cout <<"                     .::------:.                                                           "<< endl;
                cout <<"                   :---------===-:.                                                        "<< endl;
                cout <<"                 .-@---:::----@====:.                                                      "<< endl;
                cout <<"                .-@=@--::-=+=@=@==---  .:.                                                 "<< endl;
                cout <<"            :::.:-=*+---:-=+======---::-:                                                  "<< endl;
                cout <<"             ::-:-=====-----=======--::::.                                                 "<< endl;
                cout <<"            ::--:-::::::::::::::-===-----:                                                 "<< endl;
                cout <<"            .::--::.::::::::::::-===---.                                                   "<< endl;
                cout <<"              .--..: ..:::::::--==:  .:.                                                   "<< endl;
                cout <<"                     .========+++=:                                                        "<< endl;
                cout <<"                     :=-------====::                                                       "<< endl;
                cout <<"                     --::::::::-==-::                                                      "<< endl;
                cout <<"                     -=:::::::-=====-                                                      "<< endl;
                cout <<"                     :===---::---====                                                      "<< endl;
                cout <<"                     :-==::: .:-==---                                                      "<< endl;
                cout <<"                     ...      :::.                                                         "<< endl;

                break;
            case COMIENDO:
                cout <<"                                        -+--=                                                     "<< endl;
                cout <<"                                     -..::---=+                                                   "<< endl;
                cout <<"                                   =.::--=-=-=*-                                                  "<< endl;
                cout <<"                                 :.::--+=-+==++=                                                  "<< endl;
                cout <<"                             .::-::--===+==+=*+.                                                  "<< endl;
                cout <<"                         +....:::--=========*-:                                                   "<< endl;
                cout <<"                      .:.::------=========+*=.                                                    "<< endl;
                cout <<"                  ::=-#%*----============+-.                                                      "<< endl;
                cout <<"             ::==:-==.=+-=====%@@=======++                                                        "<< endl;
                cout <<"          =:=::-:-:=*=:%%%+====%+===:::=+*                                                        "<< endl;
                cout <<"         ====+=======+%%%%%% -==*::-::*=++:                                                       "<< endl;
                cout <<"          =--:-:-*==*%%%#****..==-----=++*.                                                       "<< endl;
                cout <<"         +===*#%%%#*#%=====+*..========-+:                                                        "<< endl;
                cout <<"          *#***#%##*#+---=-==..*****+****-                                                        "<< endl;
                cout <<"         =::-==***+=+*.=*----:::=#%**+==                                                          "<< endl;
                cout <<"             .:--:+==-==++**#+++=++#+=                                                            "<< endl;
                cout <<"                   :-=::--====+****       :::. ..:                                                "<< endl;
                cout <<"                      *:=*--======*+   =.         -                                               "<< endl;
                cout <<"                     :...:----====*:--.  :::::.  .:                                               "<< endl;
                cout <<"                     -  ..:--=====*-::..         =                                                "<< endl;
                cout <<"                  :-:=....==-====**=::.       ..:                                                 "<< endl;
                cout <<"           ::----:+=====::---===**+=-:.... ...::                                                  "<< endl;
                cout <<"            ::::::--:-::--=====*++=*==-::...:=                                                    "<< endl;
                cout <<"                     :=++=+***=----=+=====+-                                                      "<< endl;
                cout <<"                                   :--+=.                                                         "<< endl;
                break;
            case ENTRENANDO:
                 cout <<"                              .-+++--                                                                      "<< endl;
                 cout <<"                            .-++++++++-                                                                    "<< endl;
                 cout <<"                            -++++++++++-                                                                   "<< endl;
                 cout <<"                            -+++++++++++.                                                                  "<< endl;
                 cout <<"                            -+++++++++++.                                                                  "<< endl;
                 cout <<"                            -+++++++++++.                                                                  "<< endl;
                 cout <<"                            -+++++++++++.                                                                  "<< endl;
                 cout <<"                            -#++++++++++.                                                                  "<< endl;
                 cout <<"                            .+#++++++++-                                                                   "<< endl;
                 cout <<"                             +##++++++-.                                                                   "<< endl;
                 cout <<"                           -++++++++++-.                                                                   "<< endl;
                 cout <<".----.                  .++++++++++++++---.                                                                "<< endl;
                 cout <<"--------..             -+++++++++++++++++++-                                                               "<< endl;
                 cout <<"-----------.          -++++++++++++#.++++++--                                                              "<< endl;
                 cout <<".------------.     .--+-----++++++++##++++++#-                                                             "<< endl;
                 cout <<" -------------.     -+--+-----++++++++++++++++                                                             "<< endl;
                 cout <<" .--------------   ..---------++++##########+.                                                             "<< endl;
                 cout <<"  .----------------------------++++#######+.                                                               "<< endl;
                 cout <<"   -------------++++++---------++++++###+-.                                                                "<< endl;
                 cout <<"    ---------++++++++++-------+++----+##-                                                                  "<< endl;
                 cout <<"     -++++++++++++++++++++++++-------+##-.                                                                 "<< endl;
                 cout <<"      .++++++++++++++++++++++++++------.                                                                   "<< endl;
                 cout <<"        -++++++++++++#++++++++++##+++++-.                                                                  "<< endl;
                 cout <<"          ...-+++++-+++++++++-. .-+#++++++.                                                                "<< endl;
                 cout <<"             -++++-   .+#++++++.                                                                           "<< endl;
                break;
            case DURMIENDO:
                cout <<"                                                                                                               "<< endl;
                cout <<"                                                                                                               "<< endl;
                cout <<"  *==#===#:                                                                                                  "<< endl;
                cout <<" .*#===+====*                                                                                                "<< endl;
                cout <<"  *=+*===+====*                                                                                              "<< endl;
                cout <<"  ====++===+====*:                                                                                           "<< endl;
                cout <<"    *===+=========#.              +=                                                                         "<< endl;
                cout <<"     :+=============.            ---*                                                                        "<< endl;
                cout <<"       -+============+========**+---#.:=-*                                                                   "<< endl;
                cout <<"         =+=====================+=------=                                                                    "<< endl;
                cout <<"           #====================*=-----=           :=:-=**+=:.:=                                             "<< endl;
                cout <<"          *======================*----=--+*:   -+:......-*:-++=:*-=-                                         "<< endl;
                cout <<"          #=---===================*+=-++*%::*+.....--+.............:*:                                       "<< endl;
                cout <<"         :=----================++=#.-*===-:--==#=+:...................=                                      "<< endl;
                cout <<"         .+-::-=================+*.:=+=====-=====#::::..--#-:.......===                                      "<< endl;
                cout <<"          %===================+#:.:-*=============*=:=*::::...........:                                      "<< endl;
                cout <<"         :*=--#*========**==+*-..:*+===============*=::::::::::::....:=                                      "<< endl;
                cout <<"      *-==--=----*+=====+*#:.:=%#+==*===============+=:::::::::::::-=                                        "<< endl;
                cout <<"          #++-=---+*=:.....-#================+========*:=#+====##:                                           "<< endl;
                cout <<"         *=++--=--=#:::::#%========++=+#::::=#+=*+====+*%                                                    "<< endl;
                cout <<"         .%#@+  +-%:+###@======+++++%-                                                                       "<< endl;
                cout <<"                =+     :++#=+#                                                                               "<< endl;
                cout <<"                                                                                                               "<< endl;
                cout <<"                                                                                                               "<< endl;
                cout <<"                                                                                                               "<< endl;
                break;
            case MUERTO:
                cout <<"                           -+-                                                                   "<< endl;
                cout <<"          :.-               :.-..:             :..                                               "<< endl;
                cout <<"         --:-              *:...:-=            ::==                                              "<< endl;
                cout <<"        :::=.              :+:..-..=           -=:.:                                             "<< endl;
                cout <<"       ::-=-    =-         ::::-:::-      ==    -=:::                                            "<< endl;
                cout <<"       :=--+:  ---         ::::-:-::=    .---  =+--=.                                            "<< endl;
                cout <<"       =--=+-: =-.         =-::::--.      .-- --==---                                            "<< endl;
                cout <<"       --==------          -::=::-         =-----==--                                            "<< endl;
                cout <<"        =--=--=--        .#-:::@#.         --=-----=                                             "<< endl;
                cout <<"         ------=:      +@-. .     .:--     :+------                                              "<< endl;
                cout <<"           .---      -:=-.-:::-:.=-:::--     =-+                                                 "<< endl;
                cout <<"                   =-+::=---------::=---=.                                                       "<< endl;
                cout <<"                  *------#######*#--------=                                                      "<< endl;
                cout <<"              .  -=----##########*#+-------.                                                     "<< endl;
                cout <<"              .:=:----###%%%##%%%####-----:-:.                                                   "<< endl;
                cout <<"           .....::---%##%%%%%%%%%%###%--*::::...                                                 "<< endl;
                cout <<"             ..:::--*###%%%%%%%%%%####*-*::::.-                                                  "<< endl;
                cout <<"            ..::::+=####%%%%%%%%%%#####==-::::.                                                  "<< endl;
                cout <<"                ---*#####=       +######-=:.                                                     "<< endl;
                cout <<"                 #-%###%...........%#*##+==                                                      "<< endl;
                cout <<"                 :-%##*.............+###+:                                                       "<< endl;
                cout <<"                  =:-.................-:--                                                       "<< endl;
                cout <<"                   ==::..............:-.::                                                       "<< endl;
                cout <<"                       -::::::::::::                                                             "<< endl;
                cout <<"                           .:==:                                                                 "<< endl;
                break;
        }
    }

    /**
     * @brief Procesa el costo de energía al realizar acciones.
     * @return true Si la mascota sobrevive al esfuerzo.
     * @return false Si la mascota muere por falta de HP.
     */
    bool procesarEsfuerzo() {
        if (hp <= 0) {
            estadoActual = MUERTO;
            return false;
        }
        if (energia >= 20) {
            energia -= 20;
        } else {
            energia = 0;
            hp -= 10;
        }
        if (hp <= 0) {
            hp = 0;
            estadoActual = MUERTO;
            return false;
        }
        return true;
    }

    /**
     * @brief Aumenta la experiencia de la mascota y gestiona la subida de nivel.
     */
    void ganarExperiencia() {
        exp += 25;
        if (exp >= 100) {
            nivel++;
            exp = 0;
            hpMaximo += 5;
            hp += 5; 
        }
    }

public:
    /**
     * @brief Constructor de la clase MascotaAvanzada.
     * @param _nombre El nombre o mote que se le asignará a la mascota.
     */
    MascotaAvanzada(string _nombre) {
        nombre = _nombre;
        nivel = 1;
        exp = 0;
        amistad = 0.0f;
        energia = 100;
        hpMaximo = 50;
        hp = hpMaximo;
        hambre = 50;
        estadoActual = NORMAL;
    }

    /**
     * @brief Verifica si la mascota sigue con vida.
     * @return true Si el estado no es MUERTO.
     */
    bool estaVivo() const {
        return estadoActual != MUERTO;
    }

    void alimentar() {
        if (!estaVivo()) return;
        estadoActual = COMIENDO;
        if (procesarEsfuerzo()) {
            hambre = (hambre + 40 > 100) ? 100 : hambre + 40;
            amistad += 0.2f;
            ganarExperiencia();
        }
    }

    void entrenar() {
        if (!estaVivo()) return;
        estadoActual = ENTRENANDO;
        if (procesarEsfuerzo()) {
            hambre = (hambre - 30 < 0) ? 0 : hambre - 30;
            amistad += 0.2f;
            ganarExperiencia();
        }
    }

    void dormir() {
        if (!estaVivo()) return;
        if (hp > 0) {
            estadoActual = DURMIENDO;
            energia = 100;
            hambre = (hambre - 20 < 0) ? 0 : hambre - 20;
            amistad += 0.2f;
        }
    }

    /**
     * @brief Muestra en consola el estado actual de la mascota.
     * Utiliza gotoxy(0,0) para sobrescribir la pantalla.
     */
    void mostrarEstado() {
        gotoxy(0, 0); 
        
        dibujarMudkip();
        cout << "============= " << nombre << " (Nvl. " << nivel << ") =============" << endl;
        cout << " HP: " << hp << "/" << hpMaximo << " | Energia: " << energia << "/100       " << endl;
        cout << " Saciedad: " << hambre << "/100 | EXP: " << exp << "/100                 " << endl;
        
        int corazones = (int)(amistad / 5.0f);
        cout << " Amistad: ";
        for (int i = 0; i < 5; i++) cout << (i < corazones ? "<3 " : "_ ");
        cout << "                  " << endl; 
        cout << "==========================================" << endl;
        
        if (hp > 0) estadoActual = NORMAL;
    }
};
/**
 * @brief Función principal que ejecuta el simulador interactivo.
 * Configura la consola, solicita el nombre de la mascota y maneja el bucle principal
 * de acciones (alimentar, entrenar, dormir) hasta que el usuario sale o la mascota muere.
 * @return int Retorna 0 al finalizar la ejecución sin errores.
 */
int main() {
    string respuesta, mote;
    cout << "Bienvenido seas al simulador de mascotas" << endl;
    cout <<"                  .--------.                                             "<< endl;
    cout <<"              --+++####++++++--                                          "<< endl;
    cout <<"            +++++#-    .#+---+++--                                       "<< endl;
    cout <<"          +++####+ #### ####++++++-                                      "<< endl;
    cout <<"         +###-.  .+   +#. --####++++                                     "<< endl;
    cout <<"    --- +#         +#+        .+##+++                                    "<< endl;
    cout <<"    ----#                        -##+                                    "<< endl;
    cout <<"    -----+                          ##                                   "<< endl;
    cout <<"     --#-## .                      +#                                    "<< endl;
    cout <<"       #---++++++-                                                       "<< endl;
    cout <<"      -------@@+++.    .##.      .#                                      "<< endl;
    cout <<"      #-@---+- -######--...-##                                           "<< endl;
    cout <<"      .--@@.  +.      ..  ..#                                            "<< endl;
    cout <<"      ..-+-###-###---#+##----  #                                         "<< endl;
    cout <<"       ##    -----------+  ++.   #                                       "<< endl;
    cout <<"      -----+#++--.-++---##    #-. #                                      "<< endl;
    cout <<"        -+---..-++--..-+.----- ..+#                                      "<< endl;
    cout <<"    -## ---..-----++-++-- ++--..-#-                                      "<< endl;
    cout <<"   -+##- ++..  +++.----++-.   --##                                       "<< endl;
    cout <<"   -+###. #####.-++-+.-+ .+#-##+ .                                       "<< endl;
    cout <<"   -#####-   -##-.--.-+######   #-                                       "<< endl;
    cout <<"   --+++###-   #######        ##+-                                       "<< endl;
    cout <<"    --########             ####--                                        "<< endl;
    cout <<"     ---------+##+-----###+-----                                         "<< endl;
    cout << "y veo que has elegido a mudkip (el mejor inicial cofcof...) para comenzar tu aventura" << endl;
    cout << "Deseas ponerle un mote a Mudkip?"<< endl;
    cout << "Escribe S para si y N para no: " ;
    getline(cin, respuesta);
    mote = (respuesta == "S" || respuesta == "s") ? "" : "Mudkip";
    if (mote == "") { cout << "Mote: "; getline(cin, mote); }

    MascotaAvanzada miMascota(mote);
    
    //Limpieza de pantalla la primera vez
    system("cls"); 
    
    int op;
    do {
        miMascota.mostrarEstado();
        
        // Verificador si la mudkip está vivo o muerto para verificar su estado
        if (miMascota.estaVivo()) {
            cout << "1. Alimentar" << endl;
            cout << "2. Entrenar " << endl;
            cout << "3. Dormir " << endl;
            cout << "4. Salir " << endl;
            cout << "Accion: ";
            cin >> op;
            switch (op) {
                case 1: miMascota.alimentar(); break;
                case 2: miMascota.entrenar(); break;
                case 3: miMascota.dormir(); break;
            }
        } else {
            cout << "\n============================================" << endl;
            cout << "        Tu mascota ha fallecido...        " << endl;
            cout << "  Eres la peor escoria de la humanidad     " << endl;
            cout << " por no cuidarlo bien, a tan bella creatura " << endl;
            cout << "=============================================" << endl;
            cout << "Presiona 4 y sal de mi vista " << endl;
            cout << "Accion: ";
            cin >> op;
        }
        
    } while (op != 4);

    return 0;
}