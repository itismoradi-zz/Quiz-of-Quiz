/*   
     project phase 1                                   ;
     University: BASU University of Hamedan            ;
     faculty: engineering;  field: Computer Engineering;
     student: m.moradi;                  ID: 9812358034;          
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//functions prototype...
void graphical_welcome();
void block_question(int i);
void header_question(int i);
void data(void);

//declarations...
char username[10];
int goldenCoin=0;     //score
int ans;              //answer of question
unsigned int n_quest; //number of questions
typedef enum sub {math=1, english, sports, history, physics, art, music, contries, animal, earth} SUB;
typedef enum dif {cancel=0, easy, normal, hard} DIF;
int q_hardship;       //inputed hardship of question
int q_subject;        //inputed subject of question
int randSubj;         //random subject number
int randHard;         //random hardship number
int randAut;          //random author number

//questions data struct...
typedef struct question{
    char name_author[11];          //1 to 10
    char question_sentence[41];    //1 to 40
    DIF difficulty;                //1 to 3
    SUB subject;                   //1 to 10
    char first_pharase[21];
    char second_pharase[21];
    char third_pharase[21];
    char fourth_pharase[21];
    int answer;
}sq;

sq st[10][3][3];                   //[subject][hardship][author]



int main()
{
    data();      //all questions data
    int i;
    graphical_welcome();
    for(i=1; i<=n_quest; i++){
        startQ:
              header_question(i);
              //errors...
              if (!(q_subject==-1 || (q_subject>=1 && q_subject<=10)))
                     goto startQ;     //refresh
              if(q_hardship!=-1 && q_hardship!=0 && q_hardship!=1 && q_hardship!=2 && q_hardship!=3){
                     goto startQ;     //refresh
              }
              if(q_hardship==0){      //finish
                     system("@cls||clear");
                     printf("\n\n\n\t*****|||||...GoodBye...|||||*****\n");
                     printf("\t*****...score: %u", goldenCoin);
                     return 0;
              }
              //start to print question...
              block_question(i);

              system("@cls||clear");
              }
              //finish...
              printf("\n\n\n\t*****|||||...GoodBye...|||||*****\n");
              printf("\t*****...score: %u\n\n", goldenCoin);
    return 0;
}





//functions...
void block_question(int i){
    printf("\n\n\n===============================================================\n");
    printf("\t\t|||||??? question %i ???|||||", i);
    printf("\n===============================================================\n\n");
    if(q_subject== -1)      printf("subject: random\t\t");
    else                    printf("subject: %d\t\t", q_subject);
    if(q_hardship== -1)     printf("hardship: random\n\n");
    else                    printf("hardship: %d\n\n", q_hardship);
    //question body...
    switch (q_hardship){
          case -1:    randHard=rand()%3;
                      if(q_subject==-1)
                         randSubj=rand()%10;
                      else
                         randSubj=q_subject-1;
                      maker:
                      randAut=rand()%3;
                      if (st[randSubj][randHard][randAut].name_author== username)
                          goto maker;
                      printf("?))) %s?", st[randSubj][randHard][randAut].question_sentence);
                      printf("(author: %s)\n\n", st[randSubj][randHard][randAut].name_author);
                      printf("1) %-30s\t\t",st[randSubj][randHard][randAut].first_pharase);
                      printf("2) %-30s\n",st[randSubj][randHard][randAut].second_pharase);
                      printf("3) %-30s\t\t",st[randSubj][randHard][randAut].third_pharase);
                      printf("4) %-30s\n\n",st[randSubj][randHard][randAut].fourth_pharase);
                      break;
          case 0:     return;
                      break;
          case 1:
          case 2:
          case 3:     randHard=q_hardship-1;
                      if(q_subject==-1)
                         randSubj=rand()%10;
                      else
                         randSubj=q_subject-1;
                      maker2:
                      randAut=rand()%3;
                      if (st[randSubj][randHard][randAut].name_author== username)
                          goto maker2;
                      printf("?))) %s?", st[randSubj][randHard][randAut].question_sentence);
                      printf("(author: %s)\n\n", st[randSubj][randHard][randAut].name_author);
                      printf("1) %-30s\t\t",st[randSubj][randHard][randAut].first_pharase);
                      printf("2) %-30s\n",st[randSubj][randHard][randAut].second_pharase);
                      printf("3) %-30s\t\t",st[randSubj][randHard][randAut].third_pharase);
                      printf("4) %-30s\n",st[randSubj][randHard][randAut].fourth_pharase);
                      break;
    }

    //answer and score...
    printf("\nEnter number of answer:\n");
    scanf("%d", &ans);


    if (ans==st[randSubj][randHard][randAut].answer){
            printf("\nyour answer is \"correct\"\n");
            goldenCoin=goldenCoin+randHard+1;
            printf("\nscore: %d golden coin[s]\n", goldenCoin);
    }
    else {
            printf("\nyour answer is \"wrong\"\n");
            printf("\nscore: %d golden coin[s]\n", goldenCoin);
    }
    printf("\npress <Enter> key to continue");
    getch();      //stop printing
}

void header_question(int i){
        printf("\n\n\n===============================================================\n");
        printf("\t\t|||||??? question %i ???|||||", i);
        printf("\n===============================================================\n\n");
        //subject of question i...
        printf("\n------------------------------\n");
        printf("Please Enter number of question %i subject:      *********************", i);
        printf("\n\t\t\t\t\t\t -1: random");
        printf("\n\t\t\t\t\t\t  1: math");
        printf("\n\t\t\t\t\t\t  2: english");
        printf("\n\t\t\t\t\t\t  3: sports");
        printf("\n\t\t\t\t\t\t  4: history");
        printf("\n\t\t\t\t\t\t  5: physics");
        printf("\n\t\t\t\t\t\t  6: art");
        printf("\n\t\t\t\t\t\t  7: music");
        printf("\n\t\t\t\t\t\t  8: contries");
        printf("\n\t\t\t\t\t\t  9: animal");
        printf("\n\t\t\t\t\t\t 10: earth");
        printf("\n\t\t\t\t\t        *********************\n");
        scanf("%u", &q_subject);
        //hardship of question i...
        printf("\n------------------------------\n");
        printf("Please Enter number of question %i hardship:     *********************\n", i);
        printf("\t\t\t\t\t\t-1: random");
        printf("\n\t\t\t\t\t\t 0: cancel           \n\t\t\t\t\t ");
        printf("\t 1: easy    (1 golden coin)\n\t\t\t\t\t\t 2: normal  (2 golden coin)\n\t\t\t\t\t\t 3: hard    (3 golden coin)\n");
        printf("\t\t\t\t\t        *********************\n");
        scanf("%u", &q_hardship);
        system("@cls||clear");
}

void graphical_welcome(){
    printf("\n\n");
    printf("\t        ***********************************\n");
    printf("\t       *************************************\n");
    printf("\t      ***************************************\n");
    printf("\t     *****************************************\n");
    printf("\t    *******************************************\n");
    printf("           ?*******************************************?\n");
    printf("         ???********==========================*********???\n");
    printf("        ?????*******/                          \\*******?????\n");
    printf("      ???????*******   |||  Quiz of Quiz  |||   *******???????\n");
    printf("        ?????*******\\                          /*******?????\n");
    printf("          ???********==========================********???\n");
    printf("            ?******************************************?\n");
    printf("\t     **********<< An absorbing game >>*********\n");
    printf("\t     ******************************************\n");
    printf("\t     ******************************************\n");
    printf("\t      *****************<2020>*****************\n");
    printf("\t       **************************************\n");
    printf("\t        ************************************\n\n\n");
    printf("\n\n");
    printf("\t             press <Enter> key to start        \n");
    getch();      //stop printing
    system("@cls||clear");
    //user name...
    EnterUser:
    printf("\n\n\n");
    printf("------------------------------\n");
    printf("Please Enter your name: (1 to 10 characters)\n\n");
    gets(username);
    system("@cls||clear");
    if( strlen(username)>10 )
              goto EnterUser;
    //welcome user...
    printf("\n\t      *******************************************************\n\n");
    printf("\t\t!!! Welcome dear %-10s to Quiz of Quiz game !!!\n", username);
    printf("\t\tIn this game you should answer several questions\n");
    printf("\t\tand get golden coins.\n\n");
    printf("\t\tlet's start...\n\n\t      *******************************************************\n\n\n");
    printf("------------------------------\nPlease Enter number of quiz questions:\n\n");
    scanf("%u", &n_quest);
    system("@cls||clear");
}

void data(void){                             //all questions from Ali & Mina & Reza
                                             // "//#" means subject was changed

    //******************************Ali

    strcpy(st[0][0][0].name_author, "Ali");
    strcpy(st[0][0][0].question_sentence, "34+15");
    st[0][0][0].difficulty=1;
    st[0][0][0].subject=1;
    strcpy(st[0][0][0].first_pharase, "61");
    strcpy(st[0][0][0].second_pharase, "92");
    strcpy(st[0][0][0].third_pharase, "80");
    strcpy(st[0][0][0].fourth_pharase, "49");
    st[0][0][0].answer=4;

    strcpy(st[0][1][0].name_author, "Ali");
    strcpy(st[0][1][0].question_sentence, "22*21");
    st[0][1][0].difficulty=2;
    st[0][1][0].subject=1;
    strcpy(st[0][1][0].first_pharase, "462");
    strcpy(st[0][1][0].second_pharase, "425");
    strcpy(st[0][1][0].third_pharase, "472");
    strcpy(st[0][1][0].fourth_pharase, "400");
    st[0][1][0].answer=1;

    strcpy(st[0][2][0].name_author, "Ali");
    strcpy(st[0][2][0].question_sentence, "30%7");
    st[0][2][0].difficulty=3;
    st[0][2][0].subject=1;
    strcpy(st[0][2][0].first_pharase, "4");
    strcpy(st[0][2][0].second_pharase, "5");
    strcpy(st[0][2][0].third_pharase, "6");
    strcpy(st[0][2][0].fourth_pharase, "7");
    st[0][2][0].answer=1;
//#
    strcpy(st[1][0][0].name_author, "Ali");
    strcpy(st[1][0][0].question_sentence, "i am an...");
    st[1][0][0].difficulty=1;
    st[1][0][0].subject=2;
    strcpy(st[1][0][0].first_pharase, "doctor");
    strcpy(st[1][0][0].second_pharase, "university");
    strcpy(st[1][0][0].third_pharase, "artist");
    strcpy(st[1][0][0].fourth_pharase, "there are");
    st[1][0][0].answer=3;

    strcpy(st[1][1][0].name_author, "Ali");
    strcpy(st[1][1][0].question_sentence, "doctor is a");
    st[1][1][0].difficulty=2;
    st[1][1][0].subject=2;
    strcpy(st[1][1][0].first_pharase, "jobs");
    strcpy(st[1][1][0].second_pharase, "job");
    strcpy(st[1][1][0].third_pharase, "home");
    strcpy(st[1][1][0].fourth_pharase, "did not");
    st[1][1][0].answer=2;

    strcpy(st[1][2][0].name_author, "Ali");
    strcpy(st[1][2][0].question_sentence, "human can... the earth");
    st[1][2][0].difficulty=3;
    st[1][2][0].subject=2;
    strcpy(st[1][2][0].first_pharase, "could");
    strcpy(st[1][2][0].second_pharase, "not");
    strcpy(st[1][2][0].third_pharase, "change into");
    strcpy(st[1][2][0].fourth_pharase, "bleed");
    st[1][2][0].answer=3;
//#
    strcpy(st[2][0][0].name_author, "Ali");
    strcpy(st[2][0][0].question_sentence, "ball and foot");
    st[2][0][0].difficulty=1;
    st[2][0][0].subject=3;
    strcpy(st[2][0][0].first_pharase, "volleyball");
    strcpy(st[2][0][0].second_pharase, "swimming");
    strcpy(st[2][0][0].third_pharase, "jogging");
    strcpy(st[2][0][0].fourth_pharase, "football");
    st[2][0][0].answer=4;

    strcpy(st[2][1][0].name_author, "Ali");
    strcpy(st[2][1][0].question_sentence, "who is saeed maroof");
    st[2][1][0].difficulty=2;
    st[2][1][0].subject=3;
    strcpy(st[2][1][0].first_pharase, "football player");
    strcpy(st[2][1][0].second_pharase, "volleyball player");
    strcpy(st[2][1][0].third_pharase, "singer");
    strcpy(st[2][1][0].fourth_pharase, "swimming player");
    st[2][1][0].answer=2;

    strcpy(st[2][2][0].name_author, "Ali");
    strcpy(st[2][2][0].question_sentence, "what was Ali Daee team");
    st[2][2][0].difficulty=3;
    st[2][2][0].subject=3;
    strcpy(st[2][2][0].first_pharase, "naft");
    strcpy(st[2][2][0].second_pharase, "esteghlal");
    strcpy(st[2][2][0].third_pharase, "perspolis");
    strcpy(st[2][2][0].fourth_pharase, "pas");
    st[2][2][0].answer=3;
//#
    strcpy(st[3][0][0].name_author, "Ali");
    strcpy(st[3][0][0].question_sentence, "who was koorosh");
    st[3][0][0].difficulty=1;
    st[3][0][0].subject=4;
    strcpy(st[3][0][0].first_pharase, "USA king");
    strcpy(st[3][0][0].second_pharase, "France king");
    strcpy(st[3][0][0].third_pharase, "Iraq king");
    strcpy(st[3][0][0].fourth_pharase, "Iran king");
    st[3][0][0].answer=4;

    strcpy(st[3][1][0].name_author, "Ali");
    strcpy(st[3][1][0].question_sentence, "why pahlavi broken");
    st[3][1][0].difficulty=2;
    st[3][1][0].subject=4;
    strcpy(st[3][1][0].first_pharase, "people tries");
    strcpy(st[3][1][0].second_pharase, "emam khomeini");
    strcpy(st[3][1][0].third_pharase, "1&2");
    strcpy(st[3][1][0].fourth_pharase, "USA help");
    st[3][1][0].answer=3;

    strcpy(st[3][2][0].name_author, "Ali");
    strcpy(st[3][2][0].question_sentence, "which country built The first computer");
    st[3][2][0].difficulty=3;
    st[3][2][0].subject=4;
    strcpy(st[3][2][0].first_pharase, "Usa");
    strcpy(st[3][2][0].second_pharase, "Russia");
    strcpy(st[3][2][0].third_pharase, "Iran");
    strcpy(st[3][2][0].fourth_pharase, "English");
    st[3][2][0].answer=1;
//#
    strcpy(st[4][0][0].name_author, "Ali");
    strcpy(st[4][0][0].question_sentence, "...=0.5*m*v*v");
    st[4][0][0].difficulty=1;
    st[4][0][0].subject=5;
    strcpy(st[4][0][0].first_pharase, "v");
    strcpy(st[4][0][0].second_pharase, "a");
    strcpy(st[4][0][0].third_pharase, "k");
    strcpy(st[4][0][0].fourth_pharase, "f");
    st[4][0][0].answer=3;

    strcpy(st[4][1][0].name_author, "Ali");
    strcpy(st[4][1][0].question_sentence, "what did bohr do");
    st[4][1][0].difficulty=2;
    st[4][1][0].subject=5;
    strcpy(st[4][1][0].first_pharase, "made a formula");
    strcpy(st[4][1][0].second_pharase, "discover E=m*c*c");
    strcpy(st[4][1][0].third_pharase, "discover an atom model");
    strcpy(st[4][1][0].fourth_pharase, "did not any action");
    st[4][1][0].answer=3;

    strcpy(st[4][2][0].name_author, "Ali");
    strcpy(st[4][2][0].question_sentence, "a cable has not resistance");
    st[4][2][0].difficulty=3;
    st[4][2][0].subject=5;
    strcpy(st[4][2][0].first_pharase, "it is possible");
    strcpy(st[4][2][0].second_pharase, "it is not possible");
    strcpy(st[4][2][0].third_pharase, "we must know cable length");
    strcpy(st[4][2][0].fourth_pharase, "we must know voltage");
    st[4][2][0].answer=2;
//#
    strcpy(st[5][0][0].name_author, "Ali");
    strcpy(st[5][0][0].question_sentence, "the most famous painting of DaVinci is");
    st[5][0][0].difficulty=1;
    st[5][0][0].subject=6;
    strcpy(st[5][0][0].first_pharase, "Mirza");
    strcpy(st[5][0][0].second_pharase, "Elizabeth");
    strcpy(st[5][0][0].third_pharase, "Mona Lisa");
    strcpy(st[5][0][0].fourth_pharase, "Emam Ali");
    st[5][0][0].answer=3;

    strcpy(st[5][1][0].name_author, "Ali");
    strcpy(st[5][1][0].question_sentence, "what was vincent van gogh job");
    st[5][1][0].difficulty=2;
    st[5][1][0].subject=6;
    strcpy(st[5][1][0].first_pharase, "musician");
    strcpy(st[5][1][0].second_pharase, "painter");
    strcpy(st[5][1][0].third_pharase, "engineer");
    strcpy(st[5][1][0].fourth_pharase, "doctor");
    st[5][1][0].answer=2;

    strcpy(st[5][2][0].name_author, "Ali");
    strcpy(st[5][2][0].question_sentence, "who made inception film");
    st[5][2][0].difficulty=3;
    st[5][2][0].subject=6;
    strcpy(st[5][2][0].first_pharase, "christopher nolan");
    strcpy(st[5][2][0].second_pharase, "majid majidi");
    strcpy(st[5][2][0].third_pharase, "alfred hitchcock");
    strcpy(st[5][2][0].fourth_pharase, "Quentin Tarantino");
    st[5][2][0].answer=1;
//#
    strcpy(st[6][0][0].name_author, "Ali");
    strcpy(st[6][0][0].question_sentence, "which man was playing piano");
    st[6][0][0].difficulty=1;
    st[6][0][0].subject=7;
    strcpy(st[6][0][0].first_pharase, "Alfred Nobel");
    strcpy(st[6][0][0].second_pharase, "morteza pashaee");
    strcpy(st[6][0][0].third_pharase, "aron afshar");
    strcpy(st[6][0][0].fourth_pharase, "beethoven");
    st[6][0][0].answer=4;

    strcpy(st[6][1][0].name_author, "Ali");
    strcpy(st[6][1][0].question_sentence, "who sang jane maryam music");
    st[6][1][0].difficulty=2;
    st[6][1][0].subject=7;
    strcpy(st[6][1][0].first_pharase, "mohammad noori");
    strcpy(st[6][1][0].second_pharase, "Alireza farrokh");
    strcpy(st[6][1][0].third_pharase, "mohsen chavoshi");
    strcpy(st[6][1][0].fourth_pharase, "parvaz homay");
    st[6][1][0].answer=1;

    strcpy(st[6][2][0].name_author, "Ali");
    strcpy(st[6][2][0].question_sentence, "How many wires does Santour have");
    st[6][2][0].difficulty=3;
    st[6][2][0].subject=7;
    strcpy(st[6][2][0].first_pharase, "70");
    strcpy(st[6][2][0].second_pharase, "72");
    strcpy(st[6][2][0].third_pharase, "73");
    strcpy(st[6][2][0].fourth_pharase, "75");
    st[6][2][0].answer=2;
//#
    strcpy(st[7][0][0].name_author, "Ali");
    strcpy(st[7][0][0].question_sentence, "Which continent is Malaysia?");
    st[7][0][0].difficulty=1;
    st[7][0][0].subject=8;
    strcpy(st[7][0][0].first_pharase, "Asia");
    strcpy(st[7][0][0].second_pharase, "Europe");
    strcpy(st[7][0][0].third_pharase, "America");
    strcpy(st[7][0][0].fourth_pharase, "Africa");
    st[7][0][0].answer=1;

    strcpy(st[7][1][0].name_author, "Ali");
    strcpy(st[7][1][0].question_sentence, "Where is the capital of Sweden");
    st[7][1][0].difficulty=2;
    st[7][1][0].subject=8;
    strcpy(st[7][1][0].first_pharase, "Washington");
    strcpy(st[7][1][0].second_pharase, "Tehran");
    strcpy(st[7][1][0].third_pharase, "Geneva");
    strcpy(st[7][1][0].fourth_pharase, "stockholm");
    st[7][1][0].answer=4;

    strcpy(st[7][2][0].name_author, "Ali");
    strcpy(st[7][2][0].question_sentence, "Who is the enemy of Palestine?");
    st[7][2][0].difficulty=3;
    st[7][2][0].subject=8;
    strcpy(st[7][2][0].first_pharase, "USA");
    strcpy(st[7][2][0].second_pharase, "Britannia");
    strcpy(st[7][2][0].third_pharase, "Israel");
    strcpy(st[7][2][0].fourth_pharase, "1 & 2 & 3");
    st[7][2][0].answer=4;
//#
    strcpy(st[8][0][0].name_author, "Ali");
    strcpy(st[8][0][0].question_sentence, "which animal have body bag");
    st[8][0][0].difficulty=1;
    st[8][0][0].subject=9;
    strcpy(st[8][0][0].first_pharase, "zebra");
    strcpy(st[8][0][0].second_pharase, "donkey");
    strcpy(st[8][0][0].third_pharase, "Kangaroo");
    strcpy(st[8][0][0].fourth_pharase, "monkey");
    st[8][0][0].answer=3;

    strcpy(st[8][1][0].name_author, "Ali");
    strcpy(st[8][1][0].question_sentence, "Which animal is the human form");
    st[8][1][0].difficulty=2;
    st[8][1][0].subject=9;
    strcpy(st[8][1][0].first_pharase, "lion");
    strcpy(st[8][1][0].second_pharase, "elephant");
    strcpy(st[8][1][0].third_pharase, "donkey");
    strcpy(st[8][1][0].fourth_pharase, "monkey");
    st[8][1][0].answer=4;

    strcpy(st[8][2][0].name_author, "Ali");
    strcpy(st[8][2][0].question_sentence, "Which animal is endangered");
    st[8][2][0].difficulty=3;
    st[8][2][0].subject=9;
    strcpy(st[8][2][0].first_pharase, "frog");
    strcpy(st[8][2][0].second_pharase, "cheetah");
    strcpy(st[8][2][0].third_pharase, "donkey");
    strcpy(st[8][2][0].fourth_pharase, "girraf");
    st[8][2][0].answer=2;
//#
    strcpy(st[9][0][0].name_author, "Ali");
    strcpy(st[9][0][0].question_sentence, "where is the amazon");
    st[9][0][0].difficulty=1;
    st[9][0][0].subject=10;
    strcpy(st[9][0][0].first_pharase, "Iraq");
    strcpy(st[9][0][0].second_pharase, "USA");
    strcpy(st[9][0][0].third_pharase, "Brazil");
    strcpy(st[9][0][0].fourth_pharase, "Iran");
    st[9][0][0].answer=3;

    strcpy(st[9][1][0].name_author, "Ali");
    strcpy(st[9][1][0].question_sentence, "where is the mariana trench");
    st[9][1][0].difficulty=2;
    st[9][1][0].subject=10;
    strcpy(st[9][1][0].first_pharase, "Pacific Ocean");
    strcpy(st[9][1][0].second_pharase, "atlantic ocean");
    strcpy(st[9][1][0].third_pharase, "caspian sea");
    strcpy(st[9][1][0].fourth_pharase, "persian golf");
    st[9][1][0].answer=1;

    strcpy(st[9][2][0].name_author, "Ali");
    strcpy(st[9][2][0].question_sentence, "where is the chernobyl");
    st[9][2][0].difficulty=3;
    st[9][2][0].subject=10;
    strcpy(st[9][2][0].first_pharase, "Iran");
    strcpy(st[9][2][0].second_pharase, "Russia");
    strcpy(st[9][2][0].third_pharase, "Iraq");
    strcpy(st[9][2][0].fourth_pharase, "Japan");
    st[9][2][0].answer=2;
//#

    //******************************Mina

    strcpy(st[0][0][1].name_author, "Mina");
    strcpy(st[0][0][1].question_sentence, "29+18");
    st[0][0][1].difficulty=1;
    st[0][0][1].subject=1;
    strcpy(st[0][0][1].first_pharase, "47");
    strcpy(st[0][0][1].second_pharase, "57");
    strcpy(st[0][0][1].third_pharase, "45");
    strcpy(st[0][0][1].fourth_pharase, "55");
    st[0][0][1].answer=2;

    strcpy(st[0][1][1].name_author, "Mina");
    strcpy(st[0][1][1].question_sentence, "5+5*25/5");
    st[0][1][1].difficulty=2;
    st[0][1][1].subject=1;
    strcpy(st[0][1][1].first_pharase, "130");
    strcpy(st[0][1][1].second_pharase, "30");
    strcpy(st[0][1][1].third_pharase, "25");
    strcpy(st[0][1][1].fourth_pharase, "5");
    st[0][1][1].answer=2;

    strcpy(st[0][2][1].name_author, "Mina");
    strcpy(st[0][2][1].question_sentence, "integral sin x dx");
    st[0][2][1].difficulty=3;
    st[0][2][1].subject=1;
    strcpy(st[0][2][1].first_pharase, "-sin x");
    strcpy(st[0][2][1].second_pharase, "sin x");
    strcpy(st[0][2][1].third_pharase, "cos x");
    strcpy(st[0][2][1].fourth_pharase, "-cos x");
    st[0][2][1].answer=4;
//#
    strcpy(st[1][0][1].name_author, "Mina");
    strcpy(st[1][0][1].question_sentence, "what do yo do at nights");
    st[1][0][1].difficulty=1;
    st[1][0][1].subject=2;
    strcpy(st[1][0][1].first_pharase, "i played piano");
    strcpy(st[1][0][1].second_pharase, "i plays piano");
    strcpy(st[1][0][1].third_pharase, "i have played piano");
    strcpy(st[1][0][1].fourth_pharase, "i play piano");
    st[1][0][1].answer=4;

    strcpy(st[1][1][1].name_author, "Mina");
    strcpy(st[1][1][1].question_sentence, "i study...afternoon");
    st[1][1][1].difficulty=2;
    st[1][1][1].subject=2;
    strcpy(st[1][1][1].first_pharase, "to");
    strcpy(st[1][1][1].second_pharase, "at");
    strcpy(st[1][1][1].third_pharase, "in the");
    strcpy(st[1][1][1].fourth_pharase, "in");
    st[1][1][1].answer=3;

    strcpy(st[1][2][1].name_author, "Mina");
    strcpy(st[1][2][1].question_sentence, "i like driving...");
    st[1][2][1].difficulty=3;
    st[1][2][1].subject=2;
    strcpy(st[1][2][1].first_pharase, "fastly");
    strcpy(st[1][2][1].second_pharase, "fast");
    strcpy(st[1][2][1].third_pharase, "fastedt");
    strcpy(st[1][2][1].fourth_pharase, "faster");
    st[1][2][1].answer=2;
//#
    strcpy(st[2][0][1].name_author, "Mina");
    strcpy(st[2][0][1].question_sentence, "where was Takhti from");
    st[2][0][1].difficulty=1;
    st[2][0][1].subject=3;
    strcpy(st[2][0][1].first_pharase, "Hamedan");
    strcpy(st[2][0][1].second_pharase, "Tehran");
    strcpy(st[2][0][1].third_pharase, "Mashhad");
    strcpy(st[2][0][1].fourth_pharase, "Qum");
    st[2][0][1].answer=1;

    strcpy(st[2][1][1].name_author, "Mina");
    strcpy(st[2][1][1].question_sentence, "who is Usain Bolt");
    st[2][1][1].difficulty=2;
    st[2][1][1].subject=3;
    strcpy(st[2][1][1].first_pharase, "football player");
    strcpy(st[2][1][1].second_pharase, "swimming player");
    strcpy(st[2][1][1].third_pharase, "programmer");
    strcpy(st[2][1][1].fourth_pharase, "runner");
    st[2][1][1].answer=4;

    strcpy(st[2][2][1].name_author, "Mina");
    strcpy(st[2][2][1].question_sentence, "Who won the sixth gold ball");
    st[2][2][1].difficulty=3;
    st[2][2][1].subject=3;
    strcpy(st[2][2][1].first_pharase, "Morteza Ahmadi");
    strcpy(st[2][2][1].second_pharase, "Ronaldo");
    strcpy(st[2][2][1].third_pharase, "Messi");
    strcpy(st[2][2][1].fourth_pharase, "Ali Daee");
    st[2][2][1].answer=3;
//#
    strcpy(st[3][0][1].name_author, "Mina");
    strcpy(st[3][0][1].question_sentence, "Who is Alexander");
    st[3][0][1].difficulty=1;
    st[3][0][1].subject=4;
    strcpy(st[3][0][1].first_pharase, "a physician");
    strcpy(st[3][0][1].second_pharase, "a king");
    strcpy(st[3][0][1].third_pharase, "a engineer");
    strcpy(st[3][0][1].fourth_pharase, "a queen");
    st[3][0][1].answer=2;

    strcpy(st[3][1][1].name_author, "Mina");
    strcpy(st[3][1][1].question_sentence, "who is Mohammad");
    st[3][1][1].difficulty=2;
    st[3][1][1].subject=4;
    strcpy(st[3][1][1].first_pharase, "scientist");
    strcpy(st[3][1][1].second_pharase, "arab king");
    strcpy(st[3][1][1].third_pharase, "holy prophet");
    strcpy(st[3][1][1].fourth_pharase, "programmer");
    st[3][1][1].answer=3;

    strcpy(st[3][2][1].name_author, "Mina");
    strcpy(st[3][2][1].question_sentence, "When did World War I occur?");
    st[3][2][1].difficulty=3;
    st[3][2][1].subject=4;
    strcpy(st[3][2][1].first_pharase, "1904");
    strcpy(st[3][2][1].second_pharase, "1914");
    strcpy(st[3][2][1].third_pharase, "1919");
    strcpy(st[3][2][1].fourth_pharase, "1918");
    st[3][2][1].answer=2;
//#
    strcpy(st[4][0][1].name_author, "Mina");
    strcpy(st[4][0][1].question_sentence, "x=0.5*a*t*t+ v*...");
    st[4][0][1].difficulty=1;
    st[4][0][1].subject=5;
    strcpy(st[4][0][1].first_pharase, "t");
    strcpy(st[4][0][1].second_pharase, "v");
    strcpy(st[4][0][1].third_pharase, "x");
    strcpy(st[4][0][1].fourth_pharase, "a");
    st[4][0][1].answer=1;

    strcpy(st[4][1][1].name_author, "Mina");
    strcpy(st[4][1][1].question_sentence, "who is father of quantum");
    st[4][1][1].difficulty=2;
    st[4][1][1].subject=5;
    strcpy(st[4][1][1].first_pharase, "Nobel");
    strcpy(st[4][1][1].second_pharase, "Newton");
    strcpy(st[4][1][1].third_pharase, "Einstain");
    strcpy(st[4][1][1].fourth_pharase, "Planck");
    st[4][1][1].answer=4;

    strcpy(st[4][2][1].name_author, "Mina");
    strcpy(st[4][2][1].question_sentence, "When did Albert Einstein die?");
    st[4][2][1].difficulty=3;
    st[4][2][1].subject=5;
    strcpy(st[4][2][1].first_pharase, "1956");
    strcpy(st[4][2][1].second_pharase, "1954");
    strcpy(st[4][2][1].third_pharase, "1955");
    strcpy(st[4][2][1].fourth_pharase, "1957");
    st[4][2][1].answer=3;
//#
    strcpy(st[5][0][1].name_author, "Mina");
    strcpy(st[5][0][1].question_sentence, "who drew Self Haven");
    st[5][0][1].difficulty=1;
    st[5][0][1].subject=6;
    strcpy(st[5][0][1].first_pharase, "mohammad aali");
    strcpy(st[5][0][1].second_pharase, "farshchian");
    strcpy(st[5][0][1].third_pharase, "ali nazari");
    strcpy(st[5][0][1].fourth_pharase, "reza javadi");
    st[5][0][1].answer=2;

    strcpy(st[5][1][1].name_author, "Mina");
    strcpy(st[5][1][1].question_sentence, "who made Children of Heaven");
    st[5][1][1].difficulty=2;
    st[5][1][1].subject=6;
    strcpy(st[5][1][1].first_pharase, "majid salehi");
    strcpy(st[5][1][1].second_pharase, "leila zanganeh");
    strcpy(st[5][1][1].third_pharase, "ali parvin");
    strcpy(st[5][1][1].fourth_pharase, "majid majidi");
    st[5][1][1].answer=4;

    strcpy(st[5][2][1].name_author, "Mina");
    strcpy(st[5][2][1].question_sentence, "where is reza naji from");
    st[5][2][1].difficulty=3;
    st[5][2][1].subject=6;
    strcpy(st[5][2][1].first_pharase, "tehram");
    strcpy(st[5][2][1].second_pharase, "saveh");
    strcpy(st[5][2][1].third_pharase, "tabriz");
    strcpy(st[5][2][1].fourth_pharase, "qum");
    st[5][2][1].answer=3;
//#
    strcpy(st[6][0][1].name_author, "Mina");
    strcpy(st[6][0][1].question_sentence, "who sang taryagh");
    st[6][0][1].difficulty=1;
    st[6][0][1].subject=7;
    strcpy(st[6][0][1].first_pharase, "ali saboori");
    strcpy(st[6][0][1].second_pharase, "hichkas");
    strcpy(st[6][0][1].third_pharase, "mohsen chavoshi");
    strcpy(st[6][0][1].fourth_pharase, "mohammad noori");
    st[6][0][1].answer=3;

    strcpy(st[6][1][1].name_author, "Mina");
    strcpy(st[6][1][1].question_sentence, "which album is for chavoshi");
    st[6][1][1].difficulty=2;
    st[6][1][1].subject=7;
    strcpy(st[6][1][1].first_pharase, "bi nam");
    strcpy(st[6][1][1].second_pharase, "ebrahim");
    strcpy(st[6][1][1].third_pharase, "1&2");
    strcpy(st[6][1][1].fourth_pharase, "panjereh");
    st[6][1][1].answer=3;

    strcpy(st[6][2][1].name_author, "Mina");
    strcpy(st[6][2][1].question_sentence, "when Johann Bach dead");
    st[6][2][1].difficulty=3;
    st[6][2][1].subject=7;
    strcpy(st[6][2][1].first_pharase, "1750");
    strcpy(st[6][2][1].second_pharase, "1850");
    strcpy(st[6][2][1].third_pharase, "1950");
    strcpy(st[6][2][1].fourth_pharase, "1650");
    st[6][2][1].answer=1;
//#
    strcpy(st[7][0][1].name_author, "Mina");
    strcpy(st[7][0][1].question_sentence, "where is the iraq");
    st[7][0][1].difficulty=1;
    st[7][0][1].subject=8;
    strcpy(st[7][0][1].first_pharase, "Asia");
    strcpy(st[7][0][1].second_pharase, "Europe");
    strcpy(st[7][0][1].third_pharase, "America");
    strcpy(st[7][0][1].fourth_pharase, "isnt a contry");
    st[7][0][1].answer=1;

    strcpy(st[7][1][1].name_author, "Mina");
    strcpy(st[7][1][1].question_sentence, "Where is the capital of Ireland");
    st[7][1][1].difficulty=2;
    st[7][1][1].subject=8;
    strcpy(st[7][1][1].first_pharase, "Washington");
    strcpy(st[7][1][1].second_pharase, "Tehran");
    strcpy(st[7][1][1].third_pharase, "Dublin");
    strcpy(st[7][1][1].fourth_pharase, "Qum");
    st[7][1][1].answer=3;

    strcpy(st[7][2][1].name_author, "Mina");
    strcpy(st[7][2][1].question_sentence, "which country is republic");
    st[7][2][1].difficulty=3;
    st[7][2][1].subject=8;
    strcpy(st[7][2][1].first_pharase, "Iran");
    strcpy(st[7][2][1].second_pharase, "China");
    strcpy(st[7][2][1].third_pharase, "Iraq");
    strcpy(st[7][2][1].fourth_pharase, "1 & 2");
    st[7][2][1].answer=4;
//#
    strcpy(st[8][0][1].name_author, "Mina");
    strcpy(st[8][0][1].question_sentence, "Which animal is a mammal");
    st[8][0][1].difficulty=1;
    st[8][0][1].subject=9;
    strcpy(st[8][0][1].first_pharase, "hen");
    strcpy(st[8][0][1].second_pharase, "sheep");
    strcpy(st[8][0][1].third_pharase, "cow");
    strcpy(st[8][0][1].fourth_pharase, "2 & 3");
    st[8][0][1].answer=4;

    strcpy(st[8][1][1].name_author, "Mina");
    strcpy(st[8][1][1].question_sentence, "Which is not a domestic animal");
    st[8][1][1].difficulty=2;
    st[8][1][1].subject=9;
    strcpy(st[8][1][1].first_pharase, "dog");
    strcpy(st[8][1][1].second_pharase, "horse");
    strcpy(st[8][1][1].third_pharase, "hen");
    strcpy(st[8][1][1].fourth_pharase, "cheetah");
    st[8][1][1].answer=4;

    strcpy(st[8][2][1].name_author, "Mina");
    strcpy(st[8][2][1].question_sentence, "which animal has blue blood");
    st[8][2][1].difficulty=3;
    st[8][2][1].subject=9;
    strcpy(st[8][2][1].first_pharase, "jellyfish");
    strcpy(st[8][2][1].second_pharase, "Shrimp");
    strcpy(st[8][2][1].third_pharase, "sheep");
    strcpy(st[8][2][1].fourth_pharase, "cat");
    st[8][2][1].answer=2;
//#
    strcpy(st[9][0][1].name_author, "Mina");
    strcpy(st[9][0][1].question_sentence, "where is the 33 bridge");
    st[9][0][1].difficulty=1;
    st[9][0][1].subject=10;
    strcpy(st[9][0][1].first_pharase, "Iraq");
    strcpy(st[9][0][1].second_pharase, "Japan");
    strcpy(st[9][0][1].third_pharase, "Iran");
    strcpy(st[9][0][1].fourth_pharase, "USA");
    st[9][0][1].answer=3;

    strcpy(st[9][1][1].name_author, "Mina");
    strcpy(st[9][1][1].question_sentence, "where is the Mecca");
    st[9][1][1].difficulty=2;
    st[9][1][1].subject=10;
    strcpy(st[9][1][1].first_pharase, "Iran");
    strcpy(st[9][1][1].second_pharase, "saudi Arabia");
    strcpy(st[9][1][1].third_pharase, "Iraq");
    strcpy(st[9][1][1].fourth_pharase, "Russia");
    st[9][1][1].answer=2;

    strcpy(st[9][2][1].name_author, "Mina");
    strcpy(st[9][2][1].question_sentence, "where is the Niagara River");
    st[9][2][1].difficulty=3;
    st[9][2][1].subject=10;
    strcpy(st[9][2][1].first_pharase, "canada");
    strcpy(st[9][2][1].second_pharase, "USA");
    strcpy(st[9][2][1].third_pharase, "Iran");
    strcpy(st[9][2][1].fourth_pharase, "1 & 2");
    st[9][2][1].answer=4;
//#

    //******************************Reza

    strcpy(st[0][0][2].name_author, "Reza");
    strcpy(st[0][0][2].question_sentence, "25+35");
    st[0][0][2].difficulty=1;
    st[0][0][2].subject=1;
    strcpy(st[0][0][2].first_pharase, "60");
    strcpy(st[0][0][2].second_pharase, "92");
    strcpy(st[0][0][2].third_pharase, "80");
    strcpy(st[0][0][2].fourth_pharase, "49");
    st[0][0][2].answer=1;

    strcpy(st[0][1][2].name_author, "Reza");
    strcpy(st[0][1][2].question_sentence, "41+8*8");
    st[0][1][2].difficulty=2;
    st[0][1][2].subject=1;
    strcpy(st[0][1][2].first_pharase, "106");
    strcpy(st[0][1][2].second_pharase, "105");
    strcpy(st[0][1][2].third_pharase, "103");
    strcpy(st[0][1][2].fourth_pharase, "464");
    st[0][1][2].answer=2;

    strcpy(st[0][2][2].name_author, "Reza");
    strcpy(st[0][2][2].question_sentence, "1+2+3+4+5+6+7");
    st[0][2][2].difficulty=3;
    st[0][2][2].subject=1;
    strcpy(st[0][2][2].first_pharase, "29");
    strcpy(st[0][2][2].second_pharase, "27");
    strcpy(st[0][2][2].third_pharase, "29");
    strcpy(st[0][2][2].fourth_pharase, "28");
    st[0][2][2].answer=4;
//#
    strcpy(st[1][0][2].name_author, "Reza");
    strcpy(st[1][0][2].question_sentence, "My...is red");
    st[1][0][2].difficulty=1;
    st[1][0][2].subject=2;
    strcpy(st[1][0][2].first_pharase, "you");
    strcpy(st[1][0][2].second_pharase, "car");
    strcpy(st[1][0][2].third_pharase, "cars");
    strcpy(st[1][0][2].fourth_pharase, "2 & 3");
    st[1][0][2].answer=2;

    strcpy(st[1][1][2].name_author, "Reza");
    strcpy(st[1][1][2].question_sentence, "I...read yesterday");
    st[1][1][2].difficulty=2;
    st[1][1][2].subject=2;
    strcpy(st[1][1][2].first_pharase, "did");
    strcpy(st[1][1][2].second_pharase, "did not");
    strcpy(st[1][1][2].third_pharase, "do");
    strcpy(st[1][1][2].fourth_pharase, "does");
    st[1][1][2].answer=2;

    strcpy(st[1][2][2].name_author, "Reza");
    strcpy(st[1][2][2].question_sentence, "who...my teachers");
    st[1][2][2].difficulty=3;
    st[1][2][2].subject=2;
    strcpy(st[1][2][2].first_pharase, "is");
    strcpy(st[1][2][2].second_pharase, "am");
    strcpy(st[1][2][2].third_pharase, "there");
    strcpy(st[1][2][2].fourth_pharase, "are");
    st[1][2][2].answer=4;
//#
    strcpy(st[2][0][2].name_author, "Reza");
    strcpy(st[2][0][2].question_sentence, "sardar azmoon plays in...");
    st[2][0][2].difficulty=1;
    st[2][0][2].subject=3;
    strcpy(st[2][0][2].first_pharase, "Iraq");
    strcpy(st[2][0][2].second_pharase, "Russia");
    strcpy(st[2][0][2].third_pharase, "Africa");
    strcpy(st[2][0][2].fourth_pharase, "Japan");
    st[2][0][2].answer=2;

    strcpy(st[2][1][2].name_author, "Reza");
    strcpy(st[2][1][2].question_sentence, "who is jahanbakhsh");
    st[2][1][2].difficulty=2;
    st[2][1][2].subject=3;
    strcpy(st[2][1][2].first_pharase, "volleyball player");
    strcpy(st[2][1][2].second_pharase, "swimming player");
    strcpy(st[2][1][2].third_pharase, "physician");
    strcpy(st[2][1][2].fourth_pharase, "football player");
    st[2][1][2].answer=4;

    strcpy(st[2][2][2].name_author, "Reza");
    strcpy(st[2][2][2].question_sentence, "How many players does football play");
    st[2][2][2].difficulty=3;
    st[2][2][2].subject=3;
    strcpy(st[2][2][2].first_pharase, "14");
    strcpy(st[2][2][2].second_pharase, "20");
    strcpy(st[2][2][2].third_pharase, "22");
    strcpy(st[2][2][2].fourth_pharase, "52");
    st[2][2][2].answer=3;
//#
    strcpy(st[3][0][2].name_author, "Reza");
    strcpy(st[3][0][2].question_sentence, "who is rezashah");
    st[3][0][2].difficulty=1;
    st[3][0][2].subject=4;
    strcpy(st[3][0][2].first_pharase, "a popular man");
    strcpy(st[3][0][2].second_pharase, "a nervous man");
    strcpy(st[3][0][2].third_pharase, "a neat man");
    strcpy(st[3][0][2].fourth_pharase, "a king");
    st[3][0][2].answer=4;

    strcpy(st[3][1][2].name_author, "Reza");
    strcpy(st[3][1][2].question_sentence, "who attacked iran");
    st[3][1][2].difficulty=2;
    st[3][1][2].subject=4;
    strcpy(st[3][1][2].first_pharase, "Nobel");
    strcpy(st[3][1][2].second_pharase, "reza niazi");
    strcpy(st[3][1][2].third_pharase, "daryoosh");
    strcpy(st[3][1][2].fourth_pharase, "changiz khan");
    st[3][1][2].answer=4;

    strcpy(st[3][2][2].name_author, "Reza");
    strcpy(st[3][2][2].question_sentence, "Why the Achaemenids failed");
    st[3][2][2].difficulty=3;
    st[3][2][2].subject=4;
    strcpy(st[3][2][2].first_pharase, "they escaped");
    strcpy(st[3][2][2].second_pharase, "they was weak");
    strcpy(st[3][2][2].third_pharase, "Alexander strength");
    strcpy(st[3][2][2].fourth_pharase, "money");
    st[3][2][2].answer=3;
//#
    strcpy(st[4][0][2].name_author, "Reza");
    strcpy(st[4][0][2].question_sentence, "U= 0.5*k*x*...");
    st[4][0][2].difficulty=1;
    st[4][0][2].subject=5;
    strcpy(st[4][0][2].first_pharase, "k");
    strcpy(st[4][0][2].second_pharase, "k*x");
    strcpy(st[4][0][2].third_pharase, "x");
    strcpy(st[4][0][2].fourth_pharase, "x*x");
    st[4][0][2].answer=3;

    strcpy(st[4][1][2].name_author, "Reza");
    strcpy(st[4][1][2].question_sentence, "who said cat dead alive theory");
    st[4][1][2].difficulty=2;
    st[4][1][2].subject=5;
    strcpy(st[4][1][2].first_pharase, "plank");
    strcpy(st[4][1][2].second_pharase, "Bohr");
    strcpy(st[4][1][2].third_pharase, "erwin schrodinger");
    strcpy(st[4][1][2].fourth_pharase, "dr hessabi");
    st[4][1][2].answer=3;

    strcpy(st[4][2][2].name_author, "Reza");
    strcpy(st[4][2][2].question_sentence, "who is dr zolfigol");
    st[4][2][2].difficulty=3;
    st[4][2][2].subject=5;
    strcpy(st[4][2][2].first_pharase, "dr of chemistry");
    strcpy(st[4][2][2].second_pharase, "dr of history");
    strcpy(st[4][2][2].third_pharase, "1 & 2");
    strcpy(st[4][2][2].fourth_pharase, "physician");
    st[4][2][2].answer=1;
//#
    strcpy(st[5][0][2].name_author, "Reza");
    strcpy(st[5][0][2].question_sentence, "who is mina asghari");
    st[5][0][2].difficulty=1;
    st[5][0][2].subject=6;
    strcpy(st[5][0][2].first_pharase, "an artist");
    strcpy(st[5][0][2].second_pharase, "a musician");
    strcpy(st[5][0][2].third_pharase, "a football player");
    strcpy(st[5][0][2].fourth_pharase, "2 & 3");
    st[5][0][2].answer=2;

    strcpy(st[5][1][2].name_author, "Reza");
    strcpy(st[5][1][2].question_sentence, "who made pulpfiction film");
    st[5][1][2].difficulty=2;
    st[5][1][2].subject=6;
    strcpy(st[5][1][2].first_pharase, "ali hatami");
    strcpy(st[5][1][2].second_pharase, "Tarantino");
    strcpy(st[5][1][2].third_pharase, "Ali Ahmadi");
    strcpy(st[5][1][2].fourth_pharase, "Ali Samadi");
    st[5][1][2].answer=2;

    strcpy(st[5][2][2].name_author, "Reza");
    strcpy(st[5][2][2].question_sentence, "who drew The Scream painting");
    st[5][2][2].difficulty=3;
    st[5][2][2].subject=6;
    strcpy(st[5][2][2].first_pharase, "Edvard Munch");
    strcpy(st[5][2][2].second_pharase, "Farshchian");
    strcpy(st[5][2][2].third_pharase, "van gogh");
    strcpy(st[5][2][2].fourth_pharase, "ali minaee");
    st[5][2][2].answer=1;
//#
    strcpy(st[6][0][2].name_author, "Reza");
    strcpy(st[6][0][2].question_sentence, "who is Ebi");
    st[6][0][2].difficulty=1;
    st[6][0][2].subject=7;
    strcpy(st[6][0][2].first_pharase, "singer");
    strcpy(st[6][0][2].second_pharase, "director");
    strcpy(st[6][0][2].third_pharase, "piano player");
    strcpy(st[6][0][2].fourth_pharase, "music teacher");
    st[6][0][2].answer=1;

    strcpy(st[6][1][2].name_author, "Reza");
    strcpy(st[6][1][2].question_sentence, "moein sang...");
    st[6][1][2].difficulty=2;
    st[6][1][2].subject=7;
    strcpy(st[6][1][2].first_pharase, "hame raftand");
    strcpy(st[6][1][2].second_pharase, "prichehr");
    strcpy(st[6][1][2].third_pharase, "naneh");
    strcpy(st[6][1][2].fourth_pharase, "1 & 2 & 3");
    st[6][1][2].answer=4;

    strcpy(st[6][2][2].name_author, "Reza");
    strcpy(st[6][2][2].question_sentence, "Mah o Mahi is for hojjat...");
    st[6][2][2].difficulty=3;
    st[6][2][2].subject=7;
    strcpy(st[6][2][2].first_pharase, "ashrafzadeh");
    strcpy(st[6][2][2].second_pharase, "moosaee");
    strcpy(st[6][2][2].third_pharase, "mohammadi");
    strcpy(st[6][2][2].fourth_pharase, "modiri");
    st[6][2][2].answer=1;
//#
    strcpy(st[7][0][2].name_author, "Reza");
    strcpy(st[7][0][2].question_sentence, "where is the iran");
    st[7][0][2].difficulty=1;
    st[7][0][2].subject=8;
    strcpy(st[7][0][2].first_pharase, "USA");
    strcpy(st[7][0][2].second_pharase, "Asia");
    strcpy(st[7][0][2].third_pharase, "America");
    strcpy(st[7][0][2].fourth_pharase, "Europe");
    st[7][0][2].answer=2;

    strcpy(st[7][1][2].name_author, "Reza");
    strcpy(st[7][1][2].question_sentence, "Where is the capital of Switzerland");
    st[7][1][2].difficulty=2;
    st[7][1][2].subject=8;
    strcpy(st[7][1][2].first_pharase, "saveh");
    strcpy(st[7][1][2].second_pharase, "Tehran");
    strcpy(st[7][1][2].third_pharase, "Bern");
    strcpy(st[7][1][2].fourth_pharase, "Eshgh Abad");
    st[7][1][2].answer=3;

    strcpy(st[7][2][2].name_author, "Reza");
    strcpy(st[7][2][2].question_sentence, "Where is the Boot Country?");
    st[7][2][2].difficulty=3;
    st[7][2][2].subject=8;
    strcpy(st[7][2][2].first_pharase, "ran");
    strcpy(st[7][2][2].second_pharase, "Germany");
    strcpy(st[7][2][2].third_pharase, "France");
    strcpy(st[7][2][2].fourth_pharase, "Italy");
    st[7][2][2].answer=4;
//#
    strcpy(st[8][0][2].name_author, "Reza");
    strcpy(st[8][0][2].question_sentence, "Which animal is standing sleeping?");
    st[8][0][2].difficulty=1;
    st[8][0][2].subject=9;
    strcpy(st[8][0][2].first_pharase, "cat");
    strcpy(st[8][0][2].second_pharase, "horse");
    strcpy(st[8][0][2].third_pharase, "hen");
    strcpy(st[8][0][2].fourth_pharase, "frog");
    st[8][0][2].answer=2;

    strcpy(st[8][1][2].name_author, "Reza");
    strcpy(st[8][1][2].question_sentence, "What is the Greatest Mammal");
    st[8][1][2].difficulty=2;
    st[8][1][2].subject=9;
    strcpy(st[8][1][2].first_pharase, "whale");
    strcpy(st[8][1][2].second_pharase, "elephant");
    strcpy(st[8][1][2].third_pharase, "lion");
    strcpy(st[8][1][2].fourth_pharase, "fog");
    st[8][1][2].answer=1;

    strcpy(st[8][2][2].name_author, "Reza");
    strcpy(st[8][2][2].question_sentence, "Which animal consumes less water");
    st[8][2][2].difficulty=3;
    st[8][2][2].subject=9;
    strcpy(st[8][2][2].first_pharase, "bird");
    strcpy(st[8][2][2].second_pharase, "monkey");
    strcpy(st[8][2][2].third_pharase, "donkey");
    strcpy(st[8][2][2].fourth_pharase, "camel");
    st[8][2][2].answer=4;
//#
    strcpy(st[9][0][2].name_author, "Reza");
    strcpy(st[9][0][2].question_sentence, "Where is the North Pole?");
    st[9][0][2].difficulty=1;
    st[9][0][2].subject=10;
    strcpy(st[9][0][2].first_pharase, "it is not a Specified");
    strcpy(st[9][0][2].second_pharase, "USA");
    strcpy(st[9][0][2].third_pharase, "Canada");
    strcpy(st[9][0][2].fourth_pharase, "Russia");
    st[9][0][2].answer=1;

    strcpy(st[9][1][2].name_author, "Reza");
    strcpy(st[9][1][2].question_sentence, "Where is Angel Falls");
    st[9][1][2].difficulty=2;
    st[9][1][2].subject=10;
    strcpy(st[9][1][2].first_pharase, "abadan");
    strcpy(st[9][1][2].second_pharase, "tehran");
    strcpy(st[9][1][2].third_pharase, "america");
    strcpy(st[9][1][2].fourth_pharase, "canada");
    st[9][1][2].answer=3;

    strcpy(st[9][2][2].name_author, "Reza");
    strcpy(st[9][2][2].question_sentence, "where is the pizza tower");
    st[9][2][2].difficulty=3;
    st[9][2][2].subject=10;
    strcpy(st[9][2][2].first_pharase, "Iran");
    strcpy(st[9][2][2].second_pharase, "Irag");
    strcpy(st[9][2][2].third_pharase, "Italy");
    strcpy(st[9][2][2].fourth_pharase, "France");
    st[9][2][2].answer=3;
}

//29 Jan 2020
//THE END...