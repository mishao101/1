#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct kniga
  { char name[100];
    char adress[100];
    char number[100];
    struct kniga *next;
    struct kniga *prev;
   } kniga ;
 kniga *first;
 kniga *last; 
 kniga *fid(char *);
 void creater(kniga *n,  kniga **first, kniga **last);
 void spisok (kniga *zuerst);
 void delete(kniga *zuerst, kniga *letzte, kniga **first, kniga **last);
 void new(void);
 void search(void);
 void save(void);
 void take();
 void chief();
 
 
 int main() { printf("Вы открыли телефонную книгу.\nС помощью этого приложения вы можете записывать, сохранять, удалять, просматривать контактные данные:имя, адрес и номер телефона."); chief(); return 0;}
 void chief(void)
 {    int d;
      printf ("\n\n"); 
      printf ("  Чтобы открыть список контактов, введите 1 \n");
      printf ("  Чтобы найти контакт, введите 2  \n");
      printf ("  Чтобы удалить контакт, введите 3 \n");
      printf ("  Чтобы добавить контакт, введите 4\n"); 
      printf ("  Чтобы сохранить контакты в файл 'kniga.txt', введите 5\n");
      printf ("  Чтобы загрузить контакты из файла 'kniga.txt', введите 6 \n"); 
      printf ("  Чтобы закрыть телефонную книгу, введите 7  \n");

          scanf("%d",&d);
         if ((d<=0)|(d>7)) {printf("Вы ввели неверную команду");chief();}
         if (d==1) spisok(first);
         if (d==2) search();
         if (d==3) delete(first,last,&first,&last);  
         if (d==4) new();  
	 if (d==5) save();
         if (d==6) take();
         if (d==7) {printf("Телефонная книга закрыта \n\n");exit(0);}
             d=0;

  }

 void spisok (kniga *zuerst)
   { if(zuerst)
    { while(zuerst) {
     			printf("Имя: %s \n",zuerst->name);
     			printf("Адрес : %s \n",zuerst->adress); 
     			printf("Телефон : %s\n\n",zuerst->number);
			zuerst=zuerst->next;
   		     } 
      printf("Список контактов перед вами, введите одну из интересующих цифр:\n");
      chief(); 
     }
    else { printf("Список контактов пока пуст, вы можете добавить контакт, введя 2 в терминал") ; 
    chief();
         } 
    }
  

  void new (void)
   {  
       kniga *letzte ;
       char cat,cat2;
        
     if (!(kniga *)malloc(sizeof (kniga)))
          { printf ("Память заполнена");
         return;    
	  }
     
     letzte=(kniga *)malloc(sizeof (kniga));
  
    printf("Введите имя для нового контакта, пожалуйста:\n");  
    scanf("%s",letzte->name);
    printf("Введите адрес для нового контакта через пробел, например, ул.Политехническая д.1, пожалуйста:\n"); 
    fgets(letzte->adress,100,stdin);
    fgets(letzte->adress,100,stdin);
    printf("Введите номер для нового контакта, пожалуйста:\n");  
    scanf("%s",letzte->number);
    printf(" Контакт %s успешно добавлен.",letzte->name);
    creater(letzte, &first , &last);
    chief();
    
   }

void creater(struct kniga *n, struct kniga **zuerst, struct kniga **letzte)
{
struct kniga *a, *b, *next;
   if(*letzte==NULL)
  {
  n->next=NULL;
  n->prev=NULL;
  *letzte=n;
  *zuerst=n;
  return;
  }
  b=*zuerst;
  a=NULL;
  while(b)
  {
  if(strcmp(b->name, n->name)<0)
  {
  a=b;
  b=b->next;
  }
  else
  {
  if(b->prev)
  	{
  	b->prev->next=n;
  	n->next=b;
  	n->prev=b->prev;
  	n->prev=n;
  	return;
  	}
  n-> next =b;
  n-> prev=NULL;
  b->prev=n;
  *zuerst=n;
return;
}
}
a->next=n;
n->next=NULL;
n->prev=a;
*letzte=n;
}

 void delete(kniga *zuerst, kniga *letzte, kniga **first, kniga **last)
 {  kniga *pr;
    kniga *rok;
    kniga *ls;
    char name[100];
    char *nam;
     printf ("Введите имя контакта, который хотите удалить : \n");
     scanf("%s", name);
        nam=&name[0];  
     	pr=NULL;
     	rok=zuerst;
      	while(rok) {
                    if(!strcmp(nam, rok->name)) {pr=rok;ls=rok->prev;break;}
                    rok=rok->next;
                  }
    	   if(pr) { 
              if (pr==zuerst) { 
                            *first=pr->next;                                                    
                             if(*first) {(*first)->prev=NULL;}
                        	else *last=NULL;
                               }
        	if (pr!=zuerst) 
                               {
          			ls->next=pr->next;           
             			if (pr==letzte) *last=pr->next;                   
               			}
         printf("Контакт удален.\n"); chief();
         
                   } 
      	else  { printf ("Такого контакта нет, проверьте и попробуйте снова \n"); chief();} 
  } 
       
    

 void search(void)
 {
    char name[100];
    kniga *ist ;
    kniga *rok;
    char *uk;
 
    printf("Введите имя: \n");
    scanf("%s", name);
    uk=&name[0];

    ist=NULL;
    rok=first;
     while(rok) {
                if(!strcmp(uk, rok->name)) ist=rok;                                       
                rok=rok->next;
                 } 
    
    if(ist) {
             printf("Имя %s\n", ist->name);
             printf("Адрес %s\n", ist->adress);
             printf("Телефонный номер %s\n", ist->number);
             printf("\n");
             chief();
             }
    else {printf ("Данный контакт не найден\n"); chief();}
     
 
 }


void save(void)
 {
    kniga *letzte;
    FILE *f;
    f=fopen("kniga.txt", "wb");    
    printf("\n Вы успешно сохранили свой список контактов \n");
    letzte=first;
    while(letzte) {
                 fwrite(letzte, sizeof(kniga), 1, f);
                 letzte=letzte->next;
                   }
    fclose(f); chief();
 }




void take(void)
{
	kniga *info;
    FILE *base;
    base=fopen("kniga.txt", "rb");
    if(!base) {
        printf("Файл не найден\n");
        exit (1);
               }
    while(first) {
        	info=first->next;
        	free(first);
        	first=info;
                  }
    first=last=NULL;
    while(!feof(base)) {
        	info =(kniga *)malloc( sizeof(kniga));
        	if(1 !=fread(info, sizeof(kniga), 1, base)) break;
        	creater(info, &first, &last);
    			}
    fclose(base);printf("Контакты из файла успешно загружены"); chief();
}



