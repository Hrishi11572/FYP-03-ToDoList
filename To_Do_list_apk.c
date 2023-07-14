#include<stdio.h>
#include<stdlib.h>

#define ANSI_COLOR_BRIGHT_BLUE "\x1b[94m"
#define ANSI_COLOR_BRIGHT_RED "\x1b[91m"
#define ANSI_COLOR_GREEN "\x1b[92m"
#define ANSI_COLOR_ORANGE "\x1b[38;5;208m"
#define ANSI_COLOR_YELLOW "\033[1;33m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_STYLE_BOLD "\x1b[1m"


struct list{
    char data[101] ;
    struct list * nextptr ;
    int nodecount ;
};

typedef struct list Todo ;
typedef Todo* link ;

link head , temp , newnode; ;

void printscreen()
{  
    
    system("clear") ;
    char input = '\0' ;
    printf("*******************************************************") ;
    printf("\n            The TO-DO-LIST APPLICATION");
    printf("\n") ;
    printf("*******************************************************") ;
    printf("\n\n\n") ;
    printf("                                       designed by-\n") ;
    printf("                                       Hrishikesh Tiwari\n") ;
    
}

void adjustcount( link ptr )
{   
    int i = 1 ;
     ptr = head ;

    while(ptr != NULL)
    {
        ptr->nodecount = i ;
        i++ ;
        ptr = ptr->nextptr ;
    }
}


void delete_list()
{
    system("clear");
    int x , count=1 ;

    if (head == NULL) {
        printf("Empty list || No node to delete\n");
        return;
    }

    printf("\nEnter the Node number to be deleted: ");
    scanf("%d", &x);

    if (x == 1) {
        link del = head;
        head = head->nextptr;
        free(del);
        adjustcount(temp);
        return;
    }

    link prev = head;
    link del = head->nextptr;

    while (del != NULL) {
        ++count ;
        if (count == x) {
            prev->nextptr = del->nextptr;
            free(del);
            adjustcount(temp);
            return;
        }
        prev = del;
        del = del->nextptr;
    }
    
    printf("Node number %d not found\n", x);
}




void newlist()
{  
   system("clear") ;

   int ans = 1 ; 

   int count = 1 ;

  temp = (link)malloc(sizeof(Todo)); // Allocate memory for temp

   
   head = (link)malloc( sizeof(Todo)) ;
 
      printf("\nStart Entering :\n") ;
   
     printf("%d " , count);
     fgets(head->data , 50 , stdin) ;
     head->nextptr = NULL ;
     temp = head ; 
     
     printf("\nContinue[1] | Discontinue[0] : ") ;
       fflush(stdin) ;
        scanf("%d" , &ans) ;
        printf("\n") ;

         while( ans != 0 )
        {  
        ++count ;

        newnode = (link)malloc(sizeof(Todo)) ;

        printf("%d ",count) ;

         fflush(stdin) ;

         fgets(newnode->data , 50 , stdin) ;

         newnode->nextptr = NULL ;
         temp->nextptr = newnode ;
         temp = temp->nextptr ;
 
     printf("\nContinue[1] | Discontinue[0] : ") ;
      fflush(stdin) ;
       scanf("%d" , &ans) ;
     
      if( ans == 0 )
      {
        break ;
      }
     printf("\n") ;
     
   }

}
  



void show_mylist()
{  
    

  system("clear") ;

  int count = 1 ;
  link temp ;
    temp = head ;

    if( head == NULL ) {
    printf("Empty List\n\n") ;
    } 
    else
     {
      while( temp != NULL )
      { 
        printf(ANSI_STYLE_BOLD);
       switch( (count)%5 )
        {
            case 1: printf(ANSI_COLOR_BRIGHT_RED) ;break ;
            case 2: printf(ANSI_COLOR_YELLOW) ;break ;
            case 3: printf(ANSI_COLOR_GREEN) ; break ;
            case 4: printf(ANSI_COLOR_BRIGHT_BLUE) ;break ;
            case 0: printf(ANSI_COLOR_ORANGE) ;break ;
        }
         printf("%d ." , count) ;

          count++ ;
         printf("%s\n" , temp->data ) ;
         temp = temp->nextptr ;
      }

    printf(ANSI_COLOR_RESET) ;
    }
}



void FreeAll ( link head )
{
   link temp1, temp2 ;
   temp1 = head;
   while (temp1 != NULL)  {
      temp2 = temp1 -> nextptr;
      free(temp1);
      temp1 = temp2;
} 
}

int main()
{   
    int choice  ;
     printscreen() ;

     printf("Press the numbers in the keyboard to access the options: \n") ;

     while(1){

         printf("\n") ;
         printf(" [1.] See the to-do List \n") ;
         printf(" [2.] Create new to-do List \n") ;
         printf(" [3.] Delete current to-do List \n") ;
         printf(" [4.] Exit From Application \n") ;
         
         printf("\nEnter Your Choice\n") ;
         fflush(stdin) ;
         
         scanf("%d" , &choice) ;

         getchar() ;

         switch(choice)
         {
            case 1: show_mylist() ;  break ;
                    
            case 2: newlist() ; break ;
                     
            case 3: delete_list() ; break ;
                       
            case 4: FreeAll(head) ; exit(1) ; break ;
    
           default : printf("Not a valid choice\n") ; break ;         
         }
     
     }

    return 0 ;
}

