#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>


using namespace std;

int main(int argc, char* argv[])
{
	// Check si il y a un nombre suffisant d'arguments sinon le program planterait en essayant d'acceder à un pointeur qui n'existe pas
	if (argc < 5)
	{
		printf("Nombre d'arguments insuffisant\n");
		return 1;
	}
	int pansDeCloture{ stoi(argv[1]) };
	float montantAPayer{ stof(argv[2]) };
	// convertir int en float au cas ou.
	float coutParPan{ montantAPayer / static_cast<float>(pansDeCloture) };

	// Poteaux nécessaires pour faire une clôture en ligne droite
	int poteaux{ pansDeCloture };
	montantAPayer += poteaux * 5;

	char nomFichier[10];
	// changer strcpy pour strcpy_s et strcat pour strcat_s, pour limiter la longeur du nom pour ne qu'ils dépasse le buffer et fasse planter le program.
	strcpy_s(nomFichier, 10, argv[3]);
	// changer l'extension de fichier .exe pour .txt parce qu'on ne veut pas leur permettre  de creer un fichier executable et le l'ouvrir avec la commande system plus bas ou autre chose.
	strcat_s(nomFichier, 10, ".txt");
	ofstream fichier{ nomFichier };
	// mettre le fichier dans une condition pour pas que le program plante si le fichier n'est pas writable
	if (fichier)
	{
		fichier << argv[4];
	}
	const char* msg{ argv[4] };
	printf("%s %d %f",msg, pansDeCloture, coutParPan);

	//Retrait de System(commande), Vaut mieux ne pas permettre d'utiliser une commande system ?
	//const char* commande{ argv[5] };
	//system(commande);
}
