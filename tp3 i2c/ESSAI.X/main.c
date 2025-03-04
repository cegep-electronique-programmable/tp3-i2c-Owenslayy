/**

  @Nom du fichier
 Tp3 IDC

  @Auteur
 OWENSLAY ALCIN
   
  @Sommaire
    Programme qui �crit � l?�cran I2C

*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#define   ADDRESSE_I2C_ECRAN    	40
#define   ADDRESSE_I2C_EEPROM    0x50	


/*
    D�but de l'application principale
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    uint8_t message[20];
   

    

     
  
    
    
    

    while (1)
    {
            message[0]='0';
            message[1]='9';
            message[2]='4';
            message[4]='3';
            message[5]='4';
            message[6]='5';

        // Code qui �crit 3 caract�res sur l'�cran
        while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
         I2C_SetBuffer( message, 2);                          //Passage des donn�es         
        I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture        
        while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te    

        __delay_ms(1000);
        
        
        
        
       // Tableau qui contient les adresses et les donn�es qui vont aller dans la memoire
        uint8_t EEPROM[4];
        EEPROM[0]= 0x05;
        EEPROM[1]= 0x02;
        EEPROM[2]= 0x58;
        EEPROM[3]= 0x56;
        // tableau qui va contenir les donn�e lus
        uint8_t EEPROMREAD[4];
       
        
        // Code qui lit 3 octets de la m�moire EEPROM
        // �Criture de deux octets de donn�es � la EEPROM
        //Pour un raison que j'ignore le code n'arrive pas a bien ecire dans la memoire dans en th�orie sa doit marcher
        while(I2C_Open(0x50) == I2C_BUSY);   //passage de l?adresse I2C
        I2C_SetBuffer(EEPROM, 4);				//passage de l?adresse interne sur 2 octets      
        I2C_MasterOperation(0);				//op�ration d?�criture pour l?adresse interne       
        while (I2C_Close() == I2C_BUSY);
        __delay_ms(1000);
        
        //Lecture de 3 octets de la EEPROM 
        // Encore une fois la memoire n'arrive pas a lire a la bonne d'adresse mais arrive la lire dans une adresse inconnu
       while(I2C_Open(ADDRESSE_I2C_EEPROM) == I2C_BUSY);	//passage de l?adresse EEPROM
        I2C_SetBuffer(EEPROM, 2);			//passage du tampon et du nombre de //lectures � faire
        I2C_MasterOperation(0);             //op�ration de lecture
        while (I2C_Close() == I2C_BUSY);
        while(I2C_Open(ADDRESSE_I2C_EEPROM) == I2C_BUSY);
        I2C_SetBuffer(EEPROMREAD, 2);           //passage du tampon et du nombre de //lectures � faire
       	I2C_MasterOperation(1); 
         while (I2C_Close() == I2C_BUSY);
        
        __delay_ms(100);
        // le reste ici sont des demarche que j'ai essayer afin de debugger mais sans succ�s
        
       /* while(I2C_Open(ADDRESSE_I2C_EEPROM) == I2C_BUSY); //passage de l?adresse EEPROM
        I2C_SetBuffer(EEPROMREAD, 2);           //passage du tampon et du nombre de //lectures � faire
       	I2C_MasterOperation(1);             //op�ration d?�criture pour l?adresse interne 
        while (I2C_Close() == I2C_BUSY);
        __delay_ms(995);
        
        // �Criture de deux octets de donn�es � la EEPROM
        while(I2C_Open(ADDRESSE_I2C_EEPROM) == I2C_BUSY);   //passage de l?adresse I2C
        I2C_SetBuffer(EEPROM, 2);				//passage de l?adresse interne sur 2 octets
        I2C_MasterOperation(0);				//op�ration d?�criture pour l?adresse interne       
        while (I2C_Close() == I2C_BUSY);
        __delay_ms(500);        
        
        while(I2C_Open(ADDRESSE_I2C_EEPROM) == I2C_BUSY); //passage de l?adresse EEPROM
        I2C_SetBuffer(EEPROMREAD, 2);           //passage du tampon et du nombre de //lectures � faire
       	I2C_MasterOperation(1);             //op�ration d?�criture pour l?adresse interne 
        while (I2C_Close() == I2C_BUSY);
        __delay_ms(50); */      
        
        
        

    }
    
}