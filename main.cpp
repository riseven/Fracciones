#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std ;

int acertadas = 0 ;
int preguntadas = 0 ;
int puntuacion = 0 ;

int num1, num2 ;
int den1, den2 ;

int num3, den3 ;

bool acierto ;

void MostrarCabecera()
{
	system("cls");
    cout    << "=========================================" << endl 
            << " FRACCIONES, v0.1                        " << endl
            << "-----------------------------------------" << endl
            << " Preguntas acertadas : " << acertadas << " / " << preguntadas << endl
            << "-----------------------------------------" << endl
            << " PUNTUACION: " << puntuacion << endl 
            << "=========================================" << endl << endl ;
}

void MostrarPregunta()
{
    cout    << setw(3) << num1 << "   " << setw(3) << num2 << endl
            << "--- + --- = ---" << endl
            << setw(3) << den1 << "   " << setw(3) << den2 << endl ;
    
    cout << endl ;
}

void PrepararPregunta()
{
	num1 = rand()%((puntuacion+1)*1)+1 ;
	num2 = rand()%((puntuacion+1)*1)+1 ;
	
	den1 = rand()%((puntuacion+1)*1)+1 ;
	den2 = den1 * (( rand()%(((puntuacion/5)+1)?((puntuacion/5)+1):1) )+1) ;
}

void Preguntar()
{
	cout << "NUMERADOR: " ;
	cin >> num3 ;
	cout << "DENOMINADOR: " ;
	cin >> den3 ;
}

void ComprobarRespuesta()
{
    if (!num3 && !den3)
    {
    	cout << "ADIOS" << endl ;
    	exit(0);
    }
    
    
    preguntadas++ ;
    
    int t = den2 / den1 ;
    int nt = num1 * t ;
    int dt = den2 ;
    nt += num2 ;
    
    
    if ( nt * den3 == num3 * dt )
    {
    	acertadas++ ;
    	puntuacion+=2 ;
    	acierto = true ;
    }
    else
    {
    	puntuacion-- ;
    	acierto = false ;
    }
    
    if ( puntuacion < 0 )
    {
    	puntuacion = 0 ;
    }
}

void MostrarSolucion()
{
    int t = den2 / den1 ;
    int nt = num1 * t ;
    
    cout << "La respuesta correcta era: " << nt+den2 << " / " << den2 << endl << endl ;
}

void PreguntarRepetir()
{
	string r ;
	cout << "La respuesta no fue correcta. Desea volver a intentar la misma suma? S/N: " ;
	cin >> r ;
	cout << endl ;
	if ( r == "S" || r == "s" )
	{
		return ;
	}
	MostrarSolucion();
	PrepararPregunta();
}

int main()
{
	srand(time(NULL));

    acierto = true ;
    do
    {
        MostrarCabecera();
        if ( !acierto )
        {
            PreguntarRepetir();
        }
        else
        {
            PrepararPregunta();
        }
        MostrarPregunta();
        Preguntar();
        ComprobarRespuesta();
    } while ( true ) ;
	return 0;
}
