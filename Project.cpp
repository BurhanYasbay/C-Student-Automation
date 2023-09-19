#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct department {
	int departmentID; 
	char departmentName[30]; 
} department ;

typedef struct Kisi {
	int number; 	
	char tc[20], nameSurname[20], birthday[20], birthPlace[20], gender, adress[30], tel[20],  eMail[30]   ; 
	int militaryStatus, departmentID, status;  // status = 1 ise aktif ??renci, silinmi? =0, mezun = 2	
} ogr;

typedef struct lesson {
	int lessonID; 
	int departmentID; 	
	int akts; 
	char lessonAd[30]; 
	int lecturerID; 	
	
} lesson ;

typedef struct marks {
	int noteID; 
	int lessonID; 
	int departmentID; 	
	
	int lecturerID; 	
	int studentID; 	
	float mark; 	
} marks ;


void departmentlist() ; 
void studentadd() 
{
	system("cls") ; 
	printf("student add process... \n\n") ; 
	
	ogr o1; 	
	
	FILE *numPtr = fopen("studentnumberlari.dat", "a+b") ; 
	int number=0; 
	while( fread (  &number, sizeof(int), 1, numPtr ) )  
	{		
	}
	number += 1; 
	
	o1.number= number; 
	fwrite  (  &number, sizeof(int), 1, numPtr  ); 
	fclose(numPtr); 	
	printf("TC             : ") ; scanf(" %[^\n]s", o1.tc ) ; 
	printf("Ad-Soyad       : ") ; scanf(" %[^\n]s", o1.nameSurname ) ; 
	printf("Dogum Tarih    : ") ; scanf(" %[^\n]s", o1.birthday ) ; 
	printf("Dogum Yeri     : ") ; scanf(" %[^\n]s", o1.birthPlace ) ; 
	printf("gender       : ") ; scanf(" %[^\n]s", &o1.gender ) ; 
	printf("adress          : ") ; scanf(" %[^\n]s", o1.adress ) ; 
	printf("phone        : ") ; scanf(" %[^\n]s", o1.tel ) ; 
	printf("E-Posta        : ") ; scanf(" %[^\n]s", o1.eMail ) ; 
	if( o1.gender=='e' || o1.gender=='E'  ) 
	{
	printf("Askerlik statusu\n") ; 
	printf("[Yapmadi (0), Yapti (1), Muaf(2)]  : ") ; scanf("%d", &o1.militaryStatus ) ; 		
	}
	o1.militaryStatus= 3;
	fclose(numPtr) ; 
	
	departmentlist() ; 
	
	printf("department numbersi : ") ; scanf("%d", &o1.departmentID ) ;
	o1.status=1; 
	
	FILE * ptr = fopen("studentler.dat", "a+b") ; 	
	fwrite  (  &o1, sizeof(ogr  ), 1, ptr  ); 
	fclose(ptr); 
	
	printf("%d numberli student kaydi tamam \n", o1.number ) ; 		
}

void studentSil() 
{
	system("cls") ; 
	printf("student silme process... \n\n") ; 
	
	ogr o1; 
	int number, sayac=0, sonuc =0 ; 		
	
	FILE * ptr = fopen("studentler.dat", "r+b") ; 	
	
	printf("number : ") ; scanf("%d", &number) ; 
	while(fread  (  &o1, sizeof(ogr  ), 1, ptr  ) !=NULL   )
	{
		if( number == o1.number && o1.status==1 )
		{
			sonuc=1; 
			break; 	
		}
		sayac++; 
	}
	if( sonuc==0)	
		printf("%d numberli aktif student bulunamadi \n", number ) ; 
	else
	{
		rewind(ptr) ; 
		fseek  ( ptr, (sayac) *sizeof(ogr  ), 0  ); 
		o1.status=0; 
		fwrite  (  &o1, sizeof(ogr  ), 1, ptr  ); 
		printf("%d numberli student kaydi silindi \n", number ) ; 
	}
			
	fclose(ptr); 
	
}
void studentAra() 
{
	system("cls") ; 
	printf("student arama process... \n\n") ; 
	
	ogr o1; 
	int number, sayac=0, sonuc =0 ; 		
	
	FILE * ptr = fopen("studentler.dat", "r+b") ; 	
	
	printf("number : ") ; scanf("%d", &number) ; 
	while(fread  (  &o1, sizeof(ogr  ), 1, ptr  ) !=NULL   )
	{
		if( number == o1.number   )
		{
			sonuc=1; 
			break; 	
		}
		sayac++; 
	}
	if( sonuc==0)	
		printf("%d numberli student bulunamadi \n", number ) ; 
	else
	{
		
		printf("%d numberli student bilgileri \n", number ) ; 
		printf("TC          : %s \n", o1.tc) ; 
		printf("Ad-Soyad    : %s \n", o1.nameSurname) ; 
		printf("departmentu      : %d \n", o1.departmentID) ; 
		printf("statusu      : %d \n", o1.status) ; 
		printf("adress       : %s \n", o1.adress) ; 
		printf("phone     : %s \n", o1.tel) ; 		
	}
			
	fclose(ptr); 
	
}
void studentlist () 
{
	system("cls") ; 
	printf("student list process... \n\n") ; 
	
	ogr o1; 
	FILE * ptr = fopen("studentler.dat", "r+b") ; 	
	
	departmentlist() ; 
	int departmentNo, sayac=0; 
	printf("department No : ") ; scanf("%d", &departmentNo ) ; 
	
	printf("%-20s%-20s%-30s\n", "number", "TC", "AD-SOYAD"   ) ; 
	while(fread  (  &o1, sizeof(ogr  ), 1, ptr  ) !=NULL   )
	{
		if( departmentNo== o1.departmentID && o1.status==1  ) 
		{
			printf("%-20d%-20s%-30s \n", o1.number, o1.tc, o1.nameSurname  ); 
			sayac++; 
		}
	}
	fclose(ptr); 	
	printf("\nToplam student sayisi : %d \n", sayac ); 	
	
}
void studentBelgesi() 
{
	system("cls") ; 
	printf("student belgesi processes... \n\n") ; 
	
	ogr o1; 
	int number, sayac=0, sonuc =0 ; 		
	
	FILE * ptr = fopen("studentler.dat", "r+b") ; 	
	
	printf("number : ") ; scanf("%d", &number) ; 
	while(fread  (  &o1, sizeof(ogr  ), 1, ptr  ) !=NULL   )
	{
		if( number == o1.number   )
		{
			sonuc=1; 
			break; 	
		}
		sayac++; 
	}
	if( sonuc==0)	
		printf("%d numberli student bulunamadi \n", number ) ; 
	else
	{
		if( o1.status==0 )
		{
		printf("%d numberli studentn kaydi SILINMISTIR . bilgileri asagidadir. \n", number ) ; 
		printf("TC          : %s \n", o1.tc) ; 
		printf("Ad-Soyad    : %s \n", o1.nameSurname) ; 
		printf("departmentu      : %d \n", o1.departmentID) ; 
		printf("statusu      : %d \n", o1.status) ; 
		printf("adress       : %s \n", o1.adress) ; 
		printf("phone     : %s \n", o1.tel) ; 	
			
		}
		
		else if( o1.status==1 )
		{
		printf("%d numberli student AKTIF kayitli studentdir . bilgileri asagidadir. \n", number ) ; 
		printf("TC          : %s \n", o1.tc) ; 
		printf("Ad-Soyad    : %s \n", o1.nameSurname) ; 
		printf("departmentu      : %d \n", o1.departmentID) ; 
		printf("statusu      : %d \n", o1.status) ; 
		printf("adress       : %s \n", o1.adress) ; 
		printf("phone     : %s \n", o1.tel) ; 				
		}
		else if ( o1.status == 2 )
		{		
		printf("%d numberli student Fakultemizden MEZUN olmustur . bilgileri asagidadir. \n", number ) ; 
		printf("TC          : %s \n", o1.tc) ; 
		printf("Ad-Soyad    : %s \n", o1.nameSurname) ; 
		printf("departmentu      : %d \n", o1.departmentID) ; 
		printf("statusu      : %d \n", o1.status) ; 
		printf("adress       : %s \n", o1.adress) ; 
		printf("phone     : %s \n", o1.tel) ; 	
			
		}
	}
			
	fclose(ptr); 
	
	
		
}
void studentTranskript() 
{
	
	system("cls") ; 
	printf("student transkript processes... \n\n") ; 
	
	ogr o1; 
	int number, sayac=0, sonuc =0 ; 		
	
	FILE * ptr = fopen("studentler.dat", "r+b") ; 	
	
	printf("number : ") ; scanf("%d", &number) ; 
	while(fread  (  &o1, sizeof(ogr  ), 1, ptr  ) !=NULL   )
	{
		if( number == o1.number   )
		{
			sonuc=1; 
			break; 	
		}
		sayac++; 
	}
	if( sonuc==0)	
		printf("%d numberli student bulunamadi \n", number ) ; 
	else
	{
			printf("%d numberli student BILGILERI \n\n", number ) ; 
			printf("TC          : %s \n", o1.tc) ; 
			printf("Ad-Soyad    : %s \n", o1.nameSurname) ; 
			printf("departmentu      : %d \n", o1.departmentID) ; 
			printf("statusu      : %d \n", o1.status) ; 
			printf("adress       : %s \n", o1.adress) ; 
			printf("phone     : %s \n", o1.tel) ; 
			
			
			printf("note BILGILERI \n\n\n" ) ; 
			
			marks n1;  
	
	
			FILE *ptr = fopen("marks.dat", "r+b") ; 
			printf("%-20s%-20s%-20s\n",  "lesson-ID", "student-NO", "mark" ) ; 		
			while( fread (  &n1, sizeof( marks  ), 1, ptr ) )  
			{	
				
				if( number== n1.studentID )	
				printf("%-20d%-20d%.2f\n",  n1.lessonID, n1.studentID ,  n1.mark   );  	
			}	
			fclose(ptr); 		
	}
			
	
	
	
}
void studentMezuniyet() 
{
	system("cls") ; 
	printf("student mezuniyet process... \n\n") ; 
	
	ogr o1; 
	int number, sonuc =0, sayac=0 ; 		
	
	FILE * ptr = fopen("studentler.dat", "r+b") ; 	
	
	printf("number : ") ; scanf("%d", &number) ; 
	while(fread  (  &o1, sizeof(ogr  ), 1, ptr  ) !=NULL   )
	{
		if( number == o1.number   )
		{
			sonuc=1; 
			break; 	
		}
		sayac++; 
	}
	if( sonuc==0)	
		printf("%d numberli student bulunamadi \n", number ) ; 
	else
	{
		rewind(ptr) ; 
		fseek  (  ptr,(sayac) * sizeof(ogr  ) , 0  ) ; 
		o1.status= 2; 
		fwrite  (  &o1, sizeof(ogr  ), 1, ptr  ) ; 		
		printf("%d numberli %s isimli studentnin mezuniyet processtamamlandi... \n", number, o1.nameSurname ) ; 		
	}
			
	fclose(ptr); 
	
	
	
}






int studentMenu() 
{
	int secim; 
	printf("\n\tstudent processes... \n\n") ; 
	printf("\n\t1- student add  \n") ; 
	printf("\n\t2- student Sil  \n") ; 
	printf("\n\t3- student Ara  \n") ; 	
	printf("\n\t4- student list  \n") ; 
	printf("\n\t5- student Belgesi  \n") ; 
	printf("\n\t6- student Transkript  \n") ; 
	printf("\n\t7- student Mezuniyet  \n") ; 
	printf("\n\t0- Exit \n") ; 
	printf("\n\t- Seciminiz   :  ") ;  scanf("%d", &secim) ; 
	system("cls") ; 
	return secim; 		
}




void studentprocesses() 
{
	int secim= studentMenu(); 
	while( secim != 0 )
	{
		switch(secim )
		{
			case 1: studentadd();  break; 
			case 2: studentSil();  break; 
			case 3: studentAra();  break; 
			case 4: studentlist();  break; 
			case 5: studentBelgesi();  break; 
			case 6: studentTranskript();  break; 
			case 7: studentMezuniyet();  break; 			
			case 0:  break; 
			default : printf("Hatali secim yaptiniz ! \n") ; 			
			
		}
		secim= studentMenu(); 
		
	}
	printf("student processesnden Exit yaptiniz ... \n") ; 		
	
}

void lectureradd() 
{
	system("cls") ; 
	printf("Ogretim gorevlisi addme process... \n\n") ; 
	
	ogr o1; 	
	
	FILE *numPtr = fopen("lecturernumberlari.dat", "a+b") ; 
	int number=0; 
	while( fread (  &number, sizeof(int), 1, numPtr ) )  
	{		
	}
	number += 1; 
	
	o1.number= number; 
	fwrite  (  &number, sizeof(int), 1, numPtr  ); 
	fclose(numPtr); 	
	printf("TC             : ") ; scanf(" %[^\n]s", o1.tc ) ; 
	printf("Ad-Soyad       : ") ; scanf(" %[^\n]s", o1.nameSurname ) ; 
	printf("Dogum Tarih    : ") ; scanf(" %[^\n]s", o1.birthday ) ; 
	printf("Dogum Yeri     : ") ; scanf(" %[^\n]s", o1.birthPlace ) ; 
	printf("gender       : ") ; scanf(" %[^\n]s", &o1.gender ) ; 
	printf("adress          : ") ; scanf(" %[^\n]s", o1.adress ) ; 
	printf("phone        : ") ; scanf(" %[^\n]s", o1.tel ) ; 
	printf("E-Posta        : ") ; scanf(" %[^\n]s", o1.eMail ) ; 
	if( o1.gender=='e' || o1.gender=='E'  ) 
	{
	printf("Askerlik statusu\n") ; 
	printf("[Yapmadi (0), Yapti (1), Muaf(2)]  : ") ; scanf("%d", &o1.militaryStatus ) ; 		
	}
	o1.militaryStatus= 3;
	fclose(numPtr) ; 
	
	departmentlist() ; 
	
	printf("department numbersi : ") ; scanf("%d", &o1.departmentID ) ;
	o1.status=1; 
	
	FILE * ptr = fopen("ogretimGorevlileri.dat", "a+b") ; 	
	fwrite  (  &o1, sizeof(ogr  ), 1, ptr  ); 
	fclose(ptr); 
	
	printf("%d numberli ogretim gorevlisi kaydi tamam \n", o1.number ) ; 			
	
	
}
void lecturerSil() 
{
	system("cls") ; 
	printf("Ogretim gorevlisi silme process... \n\n") ; 
	
	ogr o1; 
	int number, sayac=0, sonuc =0 ; 		
	
	FILE * ptr = fopen("ogretimGorevlileri.dat", "r+b") ; 	
	
	printf("number : ") ; scanf("%d", &number) ; 
	while(fread  (  &o1, sizeof(ogr  ), 1, ptr  ) !=NULL   )
	{
		if( number == o1.number && o1.status==1 )
		{
			sonuc=1; 
			break; 	
		}
		sayac++; 
	}
	if( sonuc==0)	
		printf("%d numberli ogretim gorevlisi bulunamadi \n", number ) ; 
	else
	{
		rewind(ptr) ; 
		fseek  ( ptr, (sayac) *sizeof(ogr  ), 0  ); 
		o1.status=0; 
		fwrite  (  &o1, sizeof(ogr  ), 1, ptr  ); 
		printf("%d numberli ogretim gorevlisinin kaydi silindi \n", number ) ; 
	}
			
	fclose(ptr); 
	
	
	
}
void lecturerAra() 
{
	system("cls") ; 
	printf("Ogretim gorevlisi arama process... \n\n") ; 
	
	ogr o1; 
	int number, sayac=0, sonuc =0 ; 		
	
	FILE * ptr = fopen("ogretimGorevlileri.dat", "r+b") ; 	
	
	printf("number : ") ; scanf("%d", &number) ; 
	while(fread  (  &o1, sizeof(ogr  ), 1, ptr  ) !=NULL   )
	{
		if( number == o1.number   )
		{
			sonuc=1; 
			break; 	
		}
		sayac++; 
	}
	if( sonuc==0)	
		printf("%d number ogretim gorevlisi bulunamadi \n", number ) ; 
	else
	{
		
		printf("%d number ogretim gorevlisi bilgileri \n", number ) ; 
		printf("TC          : %s \n", o1.tc) ; 
		printf("Ad-Soyad    : %s \n", o1.nameSurname) ;
		
		printf("departmentu      : %d \n", o1.departmentID) ; 		 
		printf("status       : %d \n", o1.status) ; 		 		
		printf("adress       : %s \n", o1.adress) ; 
		printf("phone     : %s \n", o1.tel) ; 		
	}
			
	fclose(ptr); 
	
	
	
}
void lecturerlist() 
{
	system("cls") ; 
	printf("Ogretim gorevlisi list process... \n\n") ; 
	
	ogr o1; 
	FILE * ptr = fopen("ogretimGorevlileri.dat", "r+b") ; 	
	int departmentNo, sayac=0; 
	
	printf("%-20s%-20s%-30s%-20s\n", "number", "TC", "AD-SOYAD" , "departmentU"  ) ; 
	while(fread  (  &o1, sizeof(ogr  ), 1, ptr  ) !=NULL   )
	{
		printf("%-20d%-20s%-30s%-20d\n", o1.number, o1.tc, o1.nameSurname, o1.departmentID  ); 
		sayac++; 
		 
	}
	fclose(ptr); 	
	printf("\nToplam ogretim gorevlisi sayisi : %d \n", sayac ); 
	
	
}



int lecturerMenu() 
{
	int secim; 
	printf("\n\tOgretim gorevlisi processes... \n\n") ; 
	printf("\n\t1- Ogretim Gorevlisi add  \n") ; 
	printf("\n\t2- Ogretim Gorevlisi Sil  \n") ; 
	printf("\n\t3- Ogretim Gorevlisi Ara  \n") ; 	
	printf("\n\t4- Ogretim Gorevlisi list  \n") ; 
	 
	printf("\n\t0- Exit \n") ; 
	printf("\n\t- Seciminiz   :  ") ;  scanf("%d", &secim) ; 
	system("cls") ; 
	return secim; 		
	
	
}

void lecturerprocesses() 
{
	int secim= lecturerMenu(); 
	while( secim != 0 )
	{
		switch(secim )
		{
			case 1: lectureradd();  break; 
			case 2: lecturerSil();  break; 
			case 3: lecturerAra();  break; 
			case 4: lecturerlist();  break;  			
			case 0:  break; 
			default : printf("Hatali secim yaptiniz ! \n") ; 			
			
		}
		secim= lecturerMenu() ; 
		
	}
	printf("Ogretim gorevlisi processesnden Exit yaptiniz ... \n") ; 	
	
	
	
	
}

void lessonadd() 
{
	system("cls") ; 
	printf("lesson addme process... \n\n") ; 
	lesson d1; 
	
	printf("lesson Adi : ") ; scanf(" %[^\n]s", d1.lessonAd ) ; 
	printf("AKTS : ") ; scanf(" %d", &d1.akts ) ; 
	
	
	departmentlist() ; 
	printf("department numbersi : ") ; scanf(" %d", &d1.departmentID ) ; 
	
	
	lecturerlist() ; 
	
	printf("Ogretim gorevlisi numbersi : ") ; scanf(" %d", &d1.lecturerID ) ; 
	
	
	
	FILE *numPtr = fopen("lessonnumberlari.dat", "a+b") ; 
	int number=0; 
	while( fread (  &number, sizeof(int), 1, numPtr ) )  
	{		
	}
	number += 1; 
	d1.lessonID= number; 
	fwrite  (  &number, sizeof(int), 1, numPtr  ); 
	fclose(numPtr); 	
	
	
	
	FILE *ptr = fopen("lessonler.dat", "a+b") ;  
	fwrite  (  &d1, sizeof(lesson ), 1, ptr  ); 
	fclose(ptr); 	
	printf("%d numberli lesson kaydi tamam \n", number ) ; 	
	
}
void lessonlist() 
{
	system("cls") ; 
	printf("lesson listesi ... \n\n") ; 
	
	lesson d1; 
	
	
	FILE *ptr = fopen("lessonler.dat", "r+b") ; 
	printf("%-20s%-20s%-30s%-20s\n", "department-ID", "lesson-ID",  "lesson-ADI", "Ogr.NO"  ) ; 		
	while( fread (  &d1, sizeof( lesson ), 1, ptr ) )  
	{		
		printf("%-20d%-20d%-30s%-20d\n", d1.departmentID, d1.lessonID, d1.lessonAd, d1.lecturerID   );  	
	}	
	fclose(ptr); 		
}

int lessonMenu() 
{
	int secim; 
	printf("\n\tlesson processes... \n\n") ; 
	printf("\n\t1- lesson add  \n") ; 
	printf("\n\t2- lesson list \n") ; 
	printf("\n\t0- Exit \n") ; 
	printf("\n\t1- Seciminiz   :  ") ;  scanf("%d", &secim) ; 
	system("cls") ; 
	return secim; 	
	
}


void lessonprocesses() 
{
	int secim= lessonMenu(); 
	while( secim != 0 )
	{
		switch(secim )
		{
			case 1: lessonadd();  break; 
			case 2: lessonlist();  break; 
			case 0:  break; 
			default : printf("Hatali secim yaptiniz ! \n") ; 			
			
		}
		secim= lessonMenu(); 
		
	}
	printf("lesson processesnden Exit yaptiniz ... \n") ; 	
	
	
	
	
	
}

void departmentadd() 
{
	system("cls") ; 
	printf("department addme process... \n\n") ; 
	department b1; 
	printf("department Adi : ") ; scanf(" %[^\n]s", b1.departmentName ) ; 
	
	FILE *numPtr = fopen("departmentnumberlari.dat", "a+b") ; 
	int number=0; 
	while( fread (  &number, sizeof(int), 1, numPtr ) )  
	{		
	}
	number += 1; 
	b1.departmentID= number; 
	fwrite  (  &number, sizeof(int), 1, numPtr  ); 
	fclose(numPtr); 	
	
	
	FILE *ptr = fopen("departmentler.dat", "a+b") ;  
	fwrite  (  &b1, sizeof(department ), 1, ptr  ); 
	fclose(ptr); 
	
	printf("%d numberli department kaydi tamam \n", number ) ; 	
	
}

void departmentlist () 
{
	system("cls") ; 
	printf("department listesi ... \n\n") ; 
	
	department b1; 
	
	
	FILE *ptr = fopen("departmentler.dat", "r+b") ; 
	printf("%-20s%-30s\n", "department-ID", "department-ADI"  ) ; 		
	while( fread (  &b1, sizeof(department ), 1, ptr ) )  
	{		
		printf("%-20d%-30s\n", b1.departmentID, b1.departmentName); 	
	}	
	fclose(ptr); 	
}
int departmentMenu() 
{
	int secim; 
	printf("\n\tdepartment processes... \n\n") ; 
	printf("\n\t1- department add  \n") ; 
	printf("\n\t2- department list \n") ; 
	printf("\n\t0- Exit \n") ; 
	printf("\n\t1- Seciminiz   :  ") ;  scanf("%d", &secim) ; 
	system("cls") ; 
	return secim; 	
	
}



void departmentprocesses() 
{
	int secim= departmentMenu(); 
	while( secim != 0 )
	{
		switch(secim )
		{
			case 1: departmentadd();  break; 
			case 2: departmentlist();  break; 
			case 0:  break; 
			default : printf("Hatali secim yaptiniz ! \n") ; 			
			
		}
		secim= departmentMenu(); 
		
	}
	printf("department processesnden Exit yaptiniz ... \n") ; 	
	
}

void noteadd() 
{
	system("cls") ; 
	printf("note add process... \n\n") ; 
	marks n1;  	
	
	printf("student number : ") ; scanf(" %d", &n1.studentID ) ; 
	lessonlist() ;
	printf("lesson number : ") ; scanf(" %d", &n1.lessonID ) ; 
	
	departmentlist() ; 
	printf("department number : ") ; scanf(" %d", &n1.departmentID ) ; 
	
	lecturerlist() ; 		
	printf("Ogretim gorevlisi number : ") ; scanf(" %d", &n1.lecturerID ) ; 
	
	printf("mark : ") ; scanf(" %f", &n1.mark ) ; 
	
	
	FILE *numPtr = fopen("notenumber.dat", "a+b") ; 
	int number=0; 
	while( fread (  &number, sizeof(int), 1, numPtr ) )  
	{		
	}
	number += 1; 
	n1.noteID= number; 
	fwrite  (  &number, sizeof(int), 1, numPtr  ); 
	fclose(numPtr); 
	
	FILE *ptr = fopen("marks.dat", "a+b") ;  
	fwrite  (  &n1, sizeof(marks ), 1, ptr  ); 
	fclose(ptr); 	
	printf("%d numberli note kaydi tamam \n", number ) ; 	
		
	
}
void notelist() 
{
	system("cls") ; 
	printf("note listesi ... \n\n") ; 
	
	marks n1;  
	
	
	FILE *ptr = fopen("marks.dat", "r+b") ; 
	printf("%-20s%-20s%-20s\n",  "lesson-ID", "student-NO", "mark" ) ; 		
	while( fread (  &n1, sizeof( marks  ), 1, ptr ) )  
	{		
		printf("%-20d%-20d%.2f\n",  n1.lessonID, n1.studentID ,  n1.mark   );  	
	}	
	fclose(ptr); 		
	
}

int noteMenu() 
{
	int secim; 
	printf("\n\tnote processes... \n\n") ; 
	printf("\n\t1- note add  \n") ; 
	printf("\n\t2- note list \n") ; 
	printf("\n\t0- Exit \n") ; 
	printf("\n\t1- Seciminiz   :  ") ;  scanf("%d", &secim) ; 
	system("cls") ; 
	return secim; 	
	
}


void noteprocesses() 
{
	int secim= noteMenu(); 
	while( secim != 0 )
	{
		switch(secim )
		{
			case 1: noteadd();  break; 
			case 2: notelist();  break; 
			case 0:  break; 
			default : printf("Hatali secim yaptiniz ! \n") ; 			
			
		}
		secim= noteMenu(); 
		
	}
	printf("note processes Exit yaptiniz ... \n") ; 	
	
	
}


int menu() 
{
	int secim; 
	printf("\n\tstudent ISLERI AUTOMATION\n\n") ; 
	printf("\n\t1- student PROCESSES \n") ; 
	printf("\n\t2- OGRETIM GOREVLISI PROCESSES \n") ; 
	printf("\n\t3- lesson PROCESSES \n") ; 
	printf("\n\t4- department PROCESSES \n") ; 
	printf("\n\t5- note PROCESSES \n") ; 
	printf("\n\t0- PROGRAMI KAPAT \n") ; 
	printf("\n\t1- Seciminiz   :  ") ;  scanf("%d", &secim) ; 
	system("cls"); 
	
	return secim; 	
	
}

int main ( )
{
	int secim= menu(); 
	while( secim != 0 )
	{
		switch(secim )
		{
			case 1: studentprocesses();  break; 
			case 2: lecturerprocesses();  break; 
			case 3: lessonprocesses();  break; 
			case 4: departmentprocesses();  break; 
			case 5: noteprocesses();  break; 
			case 0:  break; 
			default : printf("Hatali secim yaptiniz ! \n") ; 			
			
		}
		secim= menu(); 
		
	}
	printf("Programi kapattiniz... \n") ; 
	
	
	return 0; 
}
