 /*Turma 3-A
integrantes:
Leonardo Ferreira Colmanetti de Almeida Lima - 2131526
Caio Caminitti de Moraes - 2146079 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
//constante π
const float pi = 3.141593;

//FUNÇÃO QUE FAZ FATORIAL 
long double fatorial(int num_termos){
    long double fat = 1;
    for (int i = 1; i <= num_termos; ++i)
    {
        fat *= i;
    }
    return fat;
}

//FUNÇÃO QUE TRANSFORMA GRAUS EM RADIANOS
double trans_radiano(int angulo){
    double valor_radiano = angulo * (pi / 180.0);
    return valor_radiano;
}

//FUNÇÃO DA FORMULA DE COSSENO
double formula_cos(double angulo_rad, int num_for){
    double v_cos=0;
    for (int n = 0; n < num_for; n++)
    {
        v_cos += pow((-1), n) * (pow(angulo_rad, 2*n) / fatorial(2*n));
    }
    return v_cos;
}

//FUÇÃO DA FORMULA DE SENO
double formula_sen(double angulo_rad, int num_for){
    double v_sen = 0;
    for (int n = 0; n < num_for; n++)
    {
        v_sen += pow((-1), n) * (pow((angulo_rad), 2*n+1) / fatorial(2*n+1));
    }
    return v_sen;
}

//FUNÇÃO PARA CALCULAR O ERRO ABSOLUTO

//cosseno
double erro_absoluto_cos(double angulo_rad, int num_for){
    double valor_absoluto = 0;
    valor_absoluto = cos(angulo_rad) - formula_cos(angulo_rad, num_for);
    if (valor_absoluto < 0)
    {
        valor_absoluto *= (-1);
    }
    
    return valor_absoluto;
}

//seno
double erro_absoluto_sen(double angulo_rad, int num_for){
    double valor_absoluto = 0;
    valor_absoluto = sin(angulo_rad) - formula_sen(angulo_rad, num_for);
    if (valor_absoluto < 0)
    {
        valor_absoluto *= (-1);
    }
    
    return valor_absoluto;
}

//FUNÇÃO PARA CALCULAR O ERRO PERCENTUAL

//cosseno
double erro_porcentual_cos(double angulo_rad, int num_for){
    double valor_percentual = 0;
    valor_percentual = (1- (cos(angulo_rad)/formula_cos(angulo_rad, num_for))) * 100.0;    
    if (valor_percentual < 0)
    {
        valor_percentual *= (-1);
    }

    return valor_percentual;
}

//seno
double erro_porcentual_sen(double angulo_rad, int num_for){
    double valor_percentual = 0;
    valor_percentual = (1- (sin(angulo_rad)/formula_sen(angulo_rad, num_for))) * 100.0;    
    if (valor_percentual < 0)
    {
        valor_percentual *= (-1);
    }

    return valor_percentual;
}

//começo do int main
int main(){

    cout << fixed << setprecision(6); //limita a quantidade de casas depois da virgula
    int num_termos = 3, angulo = 0;
    int num_for = num_termos;
    double angulo_rad = 0;

    cout << "Digite um valor de angulo em graus: ";
    cin >> angulo;

    angulo_rad = trans_radiano(angulo);

    cout << endl;

//Exercício 1 e 3 com 3 termos:

cout << "<<------------------------------COM 03 TERMOS------------------------------->>"<< endl << endl;

//cout do cosseno e seno do angulo com 3 termos
    cout << "-VALOR COM " << num_termos << " TERMOS DOS ANGULOS:" << endl;
    cout << "cosseno: " << formula_cos(angulo_rad, num_for) << endl;
    cout << "seno: " << formula_sen(angulo_rad, num_for) << endl << endl;

//cout do cosseno e seno da biblioteca
    cout << "-VALOR DO ANGULO (" << angulo << ") NA BIBLIOTECA:" << endl;
    cout << "cosseno: " << cos(angulo_rad) << endl;
    cout << "seno: " << sin(angulo_rad) << endl << endl;

//cout do erro absoluto
    cout << "-ERRO ABSOLUTO ENTRE OS DOIS VALORES DO ANGULO: " << endl;
    cout << "cosseno: " << erro_absoluto_cos(angulo_rad, num_for) << endl;
    cout << "seno: " << erro_absoluto_sen(angulo_rad, num_for) << endl << endl;
//cout do erro percentual
    cout << "-ERRO PERCENTUAL ENTRE OS DOIS VALORES DO ANGULO: " << endl;
    cout << "cosseno: " << erro_porcentual_cos(angulo_rad, num_for) << "%" << endl;
    cout << "seno: " << erro_porcentual_sen(angulo_rad, num_for) << "%" << endl << endl;  

//Exercício 2 e 3 com 40 termos:

        num_termos = 40;
        num_for=num_termos;

    cout << "<<------------------------------COM 40 TERMOS------------------------------->>"<< endl << endl;

//cout do cosseno e seno do angulo com 40 termos
    cout << "-VALOR COM " << num_termos << " TERMOS DOS ANGULOS:" << endl;
    cout << "cosseno: " << formula_cos(angulo_rad, num_for) << endl;
    cout << "seno: " << formula_sen(angulo_rad, num_for) << endl << endl;

//cout do cosseno e seno da biblioteca novamente
    cout << "-VALOR DO ANGULO (" << angulo << ") NA BIBLIOTECA:" << endl;
    cout << "cosseno: " << cos(angulo_rad) << endl;
    cout << "seno: " << sin(angulo_rad) << endl << endl;

//cout do erro absoluto
    cout << "-ERRO ABSOLUTO ENTRE OS DOIS VALORES DO ANGULO: " << endl;
    cout << "cosseno: " << erro_absoluto_cos(angulo_rad, num_for) << endl;
    cout << "seno: " << erro_absoluto_sen(angulo_rad, num_for) << endl << endl;

//cout do erro percentual
    cout << "-ERRO PERCENTUAL ENTRE OS DOIS VALORES DO ANGULO: " << endl;
    cout << "cosseno: " << erro_porcentual_cos(angulo_rad, num_for) << "%" << endl;
    cout << "seno: " << erro_porcentual_sen(angulo_rad, num_for) << "%" << endl << endl; 


    return 0;
}
//Fim do int main