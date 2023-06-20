#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 127

/*
Le programme represente la conversion d'un nombre flottant en norme IEEE :
Les etapes sont :

    1  -L'utilisateur va entrer un nombre flottant
    2  -Il y a une fonction qui sépare la partie entière de la partie fractionnelle
    3  -Ensuite,la fonction va convertir la partie entiére à la base binaire
    4  -Ensuite,on va chercher la taille du nombre binaire après la conversion dans une fonction
    5  -Même chose pour la fonction de conversion de la partie reelle à la base binaire
    6  -Ensuite,on va chercher la taille du nombre binaire après la conversion dans une fonction
    7  -On a ecrit une fonction qui va retourner le signe du nombre entré par l'utilsateur
    8  - Une fonction qui va calculer la puissance pour avoir la mantisse
    9  - Une fonction qui va calculer la position dans laquelle on va savoir la position du commencement de la mantisse
    10 -Le tableau de  la mantisse en fonction de la position et de la puissance(si la puissance est positive,
                                                                                 alors on va travailler avec la partie entière,
                                                                                 on va prendre la position de la mantisse dans laquelle le '1' est apparu,
                                                                                 sinon la puissance est nègative, alors
                                                                                 on va prendre la position de la partie fractionnelle dans laquelle le '1' est apparu)

    11 -On va calculer l'exposant
    12- La conversion d'exposant en binaire et en savant la taille de ce nombre binaire pour remplir l 'exposant en '8 bits' précis
      d'après la norme ieee de '32 bits'
    13 -La construction de la norme ieee en fonction du signe, d'exposant et de la mantisse


    Exemple pour traiter le programme :

    prenons :    (1.11) en Base 10 = 0 01111111 00011100001010001111011
                 Dans ce cas, les conditions doivent être bien étudiées,pour savoir la position
                 du mantisse, on a fait une condition que si la partie entiere == 1, alors
                 la position va retourner automatiquement 0, et pour l'exposant, on a fait
                 il va retourner que 7 bits alors on va ajouter un 0 au début de l'exposant pour accomplir les 8 bits .

                 (13.15) en Base 10 = 0 10000010 10100100110011001100110

*/

/* 2- fonction d'extraction de la partie entiere*/
int Split_entier(float a){
	if(a>0) return (int)a;
	else return -1*(int)a;
}
/*fonction d'extraction de la partie reelle*/
float Split_float(float a){
	if(a>0) return a-(int)a;
	else return -1* (a-(int)a);

}
	/*3- fonction de conversion de la base decimal
	de la  partie entiere a la base binaire*/
int* Int_binary(int *bit,int partieEntier){
	    bit=malloc(sizeof(int)*50);
	    int d,i=0,reste,j,taille;
		do{
		d=partieEntier/2;
		reste=partieEntier%2;
		*(bit+i)=reste;
		partieEntier=d;
		i++;
			}while(partieEntier!=0);
		// i est le nombre des bits dans le tableau bit
		//affichage des bits binaires de la partie entiere
	   	int *q=(int*)calloc(i,sizeof(int));
	    for(j=i-1;j>=0;j--){
			*(q+i-j-1)=*(bit+j);
		}
		free(bit);
		return q;
}

/*4- la taille du nombre binaire*/
int taille_Int_binary(int *bit,int partieEntier){
	    bit=malloc(sizeof(int)*50);
	    int d,i=0,reste,j,taille;
		do{
		d=partieEntier/2;
		reste=partieEntier%2;
		*(bit+i)=reste;
		partieEntier=d;
		i++;
			}while(partieEntier!=0);
			free(bit);
		// i est le nombre des bits dans le tableau bit
		//affichage des bits binaires de la partie entiere
		return i;
}

/*5-fonction de conversion de la base decimal
	de la partie reelle a la base binaire*/
int* Float_binary(int *bit,float partieReel){

		float f,reel;
		bit=(int*)malloc(sizeof(int)*50);
		int pas=0,entier;
	   	while(pas!=30){
	   	f=2.0*partieReel;
	   	if((int)f==0){
	   		*(bit+pas)=(int)f;
			partieReel=f;

		}else if((int)f==1){
			entier=(int)f;
			reel=(f-(int)f);
			partieReel=reel;
			*(bit+pas)=entier;
		}
		pas++;
   		}
		   return bit;
}

//6-la taille de float bits
int taille_Float_binary(int *bit,float partieReel){

		float f,reel;
		bit=(int*)malloc(sizeof(int)*50);
		int pas=0,entier;
	   	while(pas!=30){
	   	f=2.0*partieReel;
	   	if((int)f==0){
	   		*(bit+pas)=(int)f;
			partieReel=f;

		}else if((int)f==1){
			entier=(int)f;
			reel=(f-(int)f);
			partieReel=reel;
			*(bit+pas)=entier;
		}
		pas++;
   		}
		   return pas;
}

/*7- fonction qui retourne le signe du nombre entry*/
int signe_a(float a){
	if (a>0) return 0;
	else return 1;
}

/* 8-fonction qui calcule la puissance pour avoir la mantisse */
int puissance_mantisse(int *bitE,int *bitF,int tailleT1,int tailleT2,int partieEntier){
	int T3[23];//mantisse
	int i,j,count,puissance,position;
	int temp,t,k,pas=0;
		if(partieEntier==0){
			for(j=0;j<tailleT2;j++){
				if(*(bitF+j)==1){
						puissance=-(pas+1);
						return puissance;
						//position du mantisse
						break;
		}
		else{
			pas++;
			continue;}
		}
}else{
	for(i=0;i<tailleT1;i++){
		if((*(bitE+i))==1){
			puissance=tailleT1-i-1;
			//puissance pour calculer l exposant
			position=i+1;
				return puissance;
			break;
		}else{
		continue;
		}
	}
}
}

/* 9- fonction qui calcule la position pour laquelle la mantisse va commencer */
int position_mantisse(int *bitE,int *bitF,int tailleT1,int tailleT2,int partieEntier){
	int T3[23];//mantisse
	int i,j,count,puissance,position;
	int temp,t,k,pas=0;
		if(partieEntier==0){
			for(j=0;j<tailleT2;j++){
				if(*(bitF+j)==1){
						puissance=-(pas+1);
						return pas+1;
						//puissance pour calculer l exposant
						//position du mantisse
						break;
		}
		else{
			pas++;
			continue;}
                }
        }else if(partieEntier==1){
                return 0;
        }else {
            for(i=0;i<tailleT1;i++){
                if((*(bitE+i))==1){
                    puissance=tailleT1-i-1;
                    position=i+1;
                        return position;
                    break;
                }else{
                continue;
                }
            }}

}

// 10-le tableau de mantisse
int* tableau_puissance_mantisse(int *mantisse,int *bitE,int *bitF,int tailleT1,int tailleT2,int partieEntier,int puissance){
        int T3[23];//mantisse
        int i,j,count,position;
		int temp,t,k,pas;
		mantisse=(int*)malloc(sizeof(int)*23);
		position=position_mantisse(bitE,bitF,tailleT1,tailleT2,partieEntier);
        if(puissance>0){
            //start
                //remplissage de tableau mantisse par BitE;
            for(i=0,j=0;i<22;i++,j++){
                        while(position<tailleT1){
                         *(mantisse+i)=*(bitE+position);
                         position++;
                         temp=j;
                         break;
                        }
                }printf("\n");
                    //remplissage de tableau mantisse par BitF;
                    int u;
                    for(i=temp+1,k=0;i<23;i++,k++){
                        *(mantisse+i)=*(bitF+k);

                }
                    return mantisse;
            //end
        }else{
                for(i=0;i<23;i++){
                                *(mantisse+i)=*(bitF+position);
                                position++;
                                    }
                                    return mantisse;

        }
}

// 11- le calcul de l'exposant
int exposant(int puissance){
	return 127+puissance;
}

//12- la construction de la norme ieee en fonction du signe, d'exposant et de la mantisse
int* ieee_norme(int *ieee,int *mantisse,int *exposant,int signe,int tailleEXPOSANT){
        ieee=(int*)malloc(sizeof(int)*32);
        int j,i,d;
        *(ieee+0)=signe;// signe
        d=8-tailleEXPOSANT;
       //d est la difference entre la taille des bits de l exposant et la taille reelle obtenue
         if(d!=0){
                for(i=1;i<d+1;i++){ // exposant
                *(ieee+i)=0;
            }
        for(i=d+1,j=0;i<9,j<tailleEXPOSANT;i++,j++){// exposant
                *(ieee+i)=*(exposant+j);
            }
            for(i=9,j=0;i<32,j<23;i++,j++){
                *(ieee+i)=*(mantisse+j);
            }
            return ieee;
         }else if(d==0){
            for(i=1,j=0;i<9,j<9;i++,j++){
                    *(ieee+i)=*(exposant+j);
                }
                for(i=9,j=0;i<32,j<23;i++,j++){
                    *(ieee+i)=*(mantisse+j);
                }
            return ieee;
         }
        printf("\n");
        // mantisse
}

// 13- affichage du conversion de la norme ieee
void afficher(int *bit,int taille){
		int i,j;
		for(i=0;i<taille;i++){
				printf("%d",*(bit+i));
			}
}

int* soustraction(int *T1,int *T2);
void binary_sum(long b1,long b2);

//14- La fonction principale main
int main(){

          // la conversion du premier nombre
        float a,partieReel1;
        int partieEntier1,i,puissance1,position1,T3[23];
        int *T1,*p1,tailleE1,tailleF1,k,signe1,tailleEXPOSANT1,d;
        int *bit_Int1,*bit_Reel1,*mantisse1,*ex1,expos1,*ieee1,*bit_exp1;
        int *x1,j,f;
        printf("enter a number: ");
        scanf("%f",&a);
        partieReel1=Split_float(a);
        partieEntier1=Split_entier(a);
        signe1=signe_a(a);
        printf("\n");
    	/*fonction de conversion de la base decimal
	   de partie entiere a la base binaire*/
        p1=Int_binary(bit_Int1,partieEntier1);
        tailleE1=taille_Int_binary(bit_Int1,partieEntier1);
        x1=Float_binary(bit_Reel1,partieReel1);
        tailleF1=taille_Float_binary(bit_Reel1,partieReel1);
        puissance1=puissance_mantisse(p1,x1,tailleE1,tailleF1,partieEntier1);
        position1=position_mantisse(p1,x1,tailleE1,tailleF1,partieEntier1);
        mantisse1=(int*)malloc(23*sizeof(int));//mantisse
        mantisse1=tableau_puissance_mantisse(mantisse1,p1,x1,tailleE1,tailleF1,partieEntier1,puissance1);
        expos1=exposant(puissance1);//exposant en int
	    ex1=Int_binary(ex1,expos1);//bits des exposants
	    tailleEXPOSANT1=taille_Int_binary(bit_exp1,expos1);
        ieee1=ieee_norme(ieee1,mantisse1,ex1,signe1,tailleEXPOSANT1);//IEEE Norme
        printf("La conversion du nombre %f vers la norme IEEE en 32 bits: ",a);
        afficher(ieee1,32); // fonction afficher de la norme IEEE
         printf("\n");

        // la conversion du deuxieme nombre
         float partieReel,b;
        int partieEntier,puissance,position;
        int *p,tailleE,tailleF,signe,tailleEXPOSANT;
        int *bit_Int,*bit_Reel,*mantisse,*ex,expos,*ieee,*bit_exp;
        int *x;

        printf("enter a number: ");
        scanf(" %f",&b);
        printf("\n");
        partieReel=Split_float(b);
        partieEntier=Split_entier(b);
        signe=signe_a(b);
    	/*fonction de conversion de la base decimal
	   de partie entiere a la base binaire*/
        p=Int_binary(bit_Int,partieEntier);
        tailleE=taille_Int_binary(bit_Int,partieEntier);
        x=Float_binary(bit_Reel,partieReel);
        tailleF=taille_Float_binary(bit_Reel,partieReel);
        puissance=puissance_mantisse(p,x,tailleE,tailleF,partieEntier);
         //printf("\n")
        position=position_mantisse(p,x,tailleE,tailleF,partieEntier);
        mantisse=(int*)malloc(23*sizeof(int));//mantisse
        mantisse=tableau_puissance_mantisse(mantisse,p,x,tailleE,tailleF,partieEntier,puissance);
        expos=exposant(puissance);//exposant en int
	    ex=Int_binary(ex,expos);//bits des exposants
	    tailleEXPOSANT=taille_Int_binary(bit_exp,expos);
        ieee=ieee_norme(ieee,mantisse,ex,signe,tailleEXPOSANT);//IEEE Norme
        printf("La conversion du nombre %f vers la norme IEEE en 32 bits: ",b);
        afficher(ieee,32); // fonction afficher de la norme IEEE
        printf("\n");
        // la soustraction
        soustraction(ieee1,ieee);
		//Addition binaire normale
		binary_sum(01110110,10000101) ;
        
        return 0;
}

// Les operations entre deux nombres binaires

int* soustraction(int *T1,int *T2){
    int *Resultat,i;
    Resultat=(int*)malloc(sizeof(int)*32);
    for(i = 31; i >= 0; i--){
                        Resultat[i] = T1[i] - T2[i];
                        if(Resultat[i] < 0){
                                    T1[i-1] = T2[i-1] - 1;
                        }
                        Resultat[i] = fabs(Resultat[i]%2);
            }
            printf("\nDifference is: ");
            for(i = 0; i<32; i++){
                        printf("%d",Resultat[i]);
            }
 return Resultat;
}

void binary_sum(long b1,long b2){
    
    int i = 0, ret = 0, sum[20];
 
    while (b1 != 0 || b2 != 0)
    {
        sum[i++] =(b1 % 10 + b2 % 10 + ret) % 2;
        ret =(b1 % 10 + b2 % 10 + ret) / 2;
        b1 = b1 / 10;
        b2 = b2 / 10;
    }
    if (ret != 0)
        sum[i++] = ret;
    --i;
    printf("La somme est: ");
    while (i >= 0)
        printf("%d", sum[i--]);
}
