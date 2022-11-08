#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    /* Instruções para compilar no terminal
    ir ao local do arquivo cpp
    Compilar:  g++ jogo_da_adivinhacao.cpp -o jogo_da_adivinhacao.exe
    Executar: ./jogo_da_adivinhacao.exe  */

    cout << "*************************************" << endl;
    cout << "* Bem-Vindos ao Jogo da Advinhacao! *" << endl;
    cout << "*************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

    char dificuldade;

    cin >> dificuldade;

    int numero_de_tentativas;

    if(dificuldade == 'F'){
        numero_de_tentativas=15;
    }else if (dificuldade == 'M'){
        numero_de_tentativas=10;
    }else {
        numero_de_tentativas = 5;
    }
    
    srand(time(NULL));

    const int NUMERO_SECRETO = rand() % 100;
    //cout << "O numero secreto e " << NUMERO_SECRETO << ". Nao conte para ninguem!" << endl; 

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas ++){

        cout << "tentativa numero "<< tentativas << endl;

        int chute;
        cout << "Qual e o seu chute?" << endl;
        cin >> chute;
        cout << "O valor do seu chute e: " << chute << endl;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos -= pontos_perdidos;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou){
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
        }else if (maior){
            cout<< "Seu chute foi maior que o numero secreto!" << endl;
        }else{ 
            cout << "Seu chute foi menor que o numero secreto!"<< endl;
        }
    }
    cout << "FIM DE JOGO." << endl;

    if(nao_acertou){
        cout << "Voce perdeu! Tente novamente" << endl;
    } else {
        cout << "Voce acertou o numero em " <<  tentativas << " tentativas." << endl;
        // esses dois seguintes são para mostrar duas casas depois da virgula
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }

}    