#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include <time.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
int e;
static int v=0;
struct dim{
int ncols,nrows,Highscore;

}para;
struct player
{
  char name[20];
  int score;

}playerx,playery,temp;
void board(int n,int m,int a[n][m]);
void inputx(int n , int m , int arr[][m],int x) ;
void inputy(int n , int m , int arr[][m]) ;
int checkwinp1(int n,int m,int a[n][m]);
void computermode(int n,int m,int a[n][m]);
int countlines();
void print_high_scores();
void saving(struct player playerxx);
int main()
{
    if(v==0){
        xml();
        v++;
        }


      int n1,m1,score1=0,score2=0,newgame=0,saves=0,select,k=1,z=1,mode,t;
      clock_t start,end;

    //main menu choose first
    printf("=============================================\n");
    printf("|         Welcome To connect 4 game         |\n");
    printf("|                                           |\n");
    printf("=============================================");
    printf("\n1.New Game");
    printf("\n2.Saved High Scores");
    printf("\n3.Load saved games");
    printf("\n4.Exit");
    printf("\nPlease choose the destination:");
    scanf("%d",&select);
    if(select!=4 && select!=3 && select != 2 && select !=1 ){
        system("cls") ;
        printf("Invalid input") ;
        Sleep(2) ;
        system("cls") ;
        main() ;
    }
    system("cls");
    n1=para.nrows;
    m1=para.ncols;
    int a1[n1][m1];
        for(int i1=0;i1<n1;i1++){
          for(int j1=0;j1<m1;j1++){
            a1[i1][j1]=' ';
          }
        }
        int l;
   if(select==3){
    printf("\n1.save1");
    printf("\n2.save2");
    printf("\n3.save3");
    scanf("\n%d",&l);
    if(l!=3 && l!=2 && l!=1){
         system("cls") ;
        printf("Invalid input") ;
        Sleep(2) ;
        system("cls") ;
        main() ;
    }
   }
   l--;
   system("cls");
   if(select==3){
    if(l==0){
    int c[2];
    loaddim0(c);
    int n1=c[0],m1=c[1];
    load0(n1,m1,a1);
    }
    else if(l==1){
    int c[2];
    loaddim1(c);
    int n1=c[0],m1=c[1];
    load1(n1,m1,a1);
    }
    else if(l==2){
    int c[2];
    loaddim2(c);
    int n1=c[0],m1=c[1];
    load2(n1,m1,a1);
    }
   }


    //choose mode
    if(select==4){
        exit(1);
    }
    else if(select==2){
        print_high_scores();
        printf("Redirection To Main Menu Again is After 10 Seconds");
        sleep(10);
        system("cls");
        main();
    }
    else if(select==1 || select==3){
    if(select ==1){
   selection(&mode);
    system("cls");}



        fflush(stdin);

    // HvH mode
    if(mode==1 || select==3){
    printf("Player 1 please enter your name:");
    fgets(playerx.name,20,stdin);
    printf("Player 2 please enter your name:");
    fgets(playery.name,20,stdin);
    playerx.score=0;
    playery.score=0;
    board(n1,m1,a1);
    int mins=0;
  for(e=0;e<n1*m1;e++){
    if(e%2==0){
        start=clock();
        inputx(n1 , m1  , a1,0);
        end=clock();
    }
    else{
        start=clock();
        inputy(n1 , m1  , a1);
        end=clock();
    }
    board(n1 , m1 , a1) ;
    double duration;
    duration+= ((double)end - start)/CLOCKS_PER_SEC;

    if(duration>59){
        mins++;
        duration=0;
    }
    printf("Time= %2d: %f",mins, duration);
    playerx.score+= checkwinp2(n1 , m1 , a1)-playerx.score;
    printf("\nscore of %s is %d" ,playerx.name, playerx.score);
    playery.score+= checkwinp1(n1 , m1 , a1)-playery.score;
    printf("\nscore of %s is %d" ,playery.name, playery.score);



  }
  if(playery.score>playerx.score){
    printf("\n       The Winner Is %s         \n",playery.name);
    printf("\nYou will be redirected to main menu in 10 seconds");
    saving(playery);
  }
  else if(playery.score<playerx.score){
    printf("\n       The Winner Is %s         \n",playerx.name);
    printf("\nYou will be redirected to main menu in 10 seconds");
    saving(playerx);
  }
  else if(playerx.score==playery.score){
    printf("\n       DRAW         \n",playery.name);
    printf("\nYou will be redirected to main menu in 10 seconds");
    saving(playerx);
    saving(playery);
  }
  sleep(10);
  system("cls");
  main();
  }

  // computer vs human mode
  else if(mode==2){
    printf("Player 1 please enter your name:");
    fgets(playerx.name,20,stdin);
    board(n1 , m1 , a1) ;
    int mins=0;
    for(int e=0;e<n1*m1;e++){
    if(e%2==0){
    start=clock();
    inputx(n1,m1 , a1,1);
    end=clock();
    }
    else{
        start=clock();
        computermode(n1,m1,a1);
        end=clock();
    }
    board(n1 , m1 , a1) ;
    double duration;
    duration+= ((double)end - start)/CLOCKS_PER_SEC;

    if(duration>59){
        mins++;
        duration=0;
    }
    printf("Time= %2d: %f",mins, duration);
    playerx.score+= checkwinp2(n1 , m1 , a1)-playerx.score;
    printf("\nscore of %s is %d" ,playerx.name, playerx.score);
    score2+= checkwinp1(n1 , m1 , a1)-score2 ;
    printf("\nscore computer is %d" , score2) ;
  }
    if(playerx.score>score2){
    printf("\n       The Winner Is %s         \n",playerx.name);
    printf("\nYou will be redirected to main menu in 10 seconds");
    saving(playerx);
    }
    else if(playerx.score<score2){
    printf("\n       YOU LOST :\\(         \n",playerx.name);
    printf("\nYou will be redirected to main menu in 10 seconds");
    }
    else if(playerx.score==score2){
    printf("\n       DRAW         \n",playerx.name);
    printf("\nYou will be redirected to main menu in 10 seconds");
    saving(playerx);
    }
    sleep(10);
    system("cls");
    main();
}
    }
}
void board(int n,int m,int a[n][m]){

        system("cls");
        int i,j,k;
        for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("|");
            if(a[i][j]==88){
            printf(RED"%c"RESET,a[i][j]);}
            else{
                printf(BLU"%c"RESET,a[i][j]);
            }
            printf("|");
        }
        printf("\n");
    }
    for(i=0;i<m;i++){
        printf("===");
    }
    printf("\n");
    for(i=0;i<m;i++){
        if(i<10){
        printf(" %d ",i+1);}
        else{
            printf("%d ",i+1);
        }
    }


}



void inputy(int n , int m , int arr[][m]){
int i ;
int cPlace ;
int found = 0 ;
printf("\n %s input the column\n",playery);
printf("\n                                                               YOU CAN PRESS (-5) TO SAVE AND EXIT\n");
printf("\n                                                               YOU CAN PRESS (-4) TO EXIT\n");
scanf("%d" , &cPlace);
if(cPlace==-4){
    system("cls");
    main();
}
while(cPlace<=0 && cPlace!=-5 && cPlace!=-4){
    printf("Invalid input") ;
    scanf("%d" , &cPlace);
}


cPlace-- ;
if(cPlace==-6){
    savecaller(n,m,arr);
    main();
}
for(i=n-1 ; i>=0 ; i--){
    if ( arr[i][cPlace]==' '){

       arr[i][cPlace]=89 ;
         found = 1 ;
         break ;
    }
}

if(found==0){
    printf("no empty spaces") ;
    inputy(n , m  ,arr) ;
}
}
//--------------
void inputx(int n , int m , int arr[][m],int x){
int i ;
int cPlace ;
int found = 0 ;
printf("\n %s input the column\n",playerx) ;
if(x==0){
printf("\n                                                               YOU CAN PRESS (-5) TO SAVE AND EXIT\n");}
printf("\n                                                               YOU CAN PRESS (-4) TO EXIT\n");
scanf("%d" , &cPlace) ;
if(cPlace==-4){
    system("cls");
    main();
}
while(cPlace<=0 && cPlace!=-5 && cPlace!=-4){
    printf("Invalid input") ;
    scanf("%d" , &cPlace);
}
cPlace-- ;
if(x==0){
if(cPlace==-6){
    savecaller(n,m,arr);
    main();
}}
for(i=n-1 ; i>=0 ; i--){
    if ( arr[i][cPlace]==' '){

       arr[i][cPlace]=88 ;
         found = 1 ;
         break ;
    }
}

if(found==0){
    printf("no empty spaces") ;
    if(x==0){
    inputx(n , m  ,arr,0) ;}
    else{
        inputx(n , m  ,arr,1) ;
    }
}

}







int checkwinp1(int n,int m,int a[n][m]){
 int player1score=0;
 int r,c,r1,c1,z=1,t=0,flag=0;
 for(r=n-1;r>=0;r--){
        flag=0;
        z=1;
        t=0;
    for(c=0;c<m;c++){
        //side right check
        if((c+1<=m-1)&&(c+2<=m-1)&&(c+3<=m-1)){
        for(c1=c+1;z<4;z++){
            if((a[r][c1]==89)&&(a[r][c]==89)){
                t++;
            }
            c1++;
        }
    }
        if(t==3){
            player1score++;
            flag=1;
        }
        t=0;
        z=1;

        //left up diagonal check
    if((c-1>=0)&&(c-2>=0)&&(c-3>=0)&&(r-1>=0)&&(r-2>=0)&&(r-3>=0)){
            r1=r-1;
        for(c1=c-1;z<4;z++){

            if((a[r1][c1]==89)&&(a[r][c]==89)){
                t++;
            }
            c1--;
            r1--;
        }
    }
        if(t==3){
            player1score++;
          flag=1;
        }
        t=0;
        z=1;
        //up check
        if((r-1>=0)&&(r-2>=0)&&(r-3>=0)){
        for(r1=r-1;z<4;z++){
            if((a[r1][c]==89)&&(a[r][c]==89)){
                t++;
            }
            r1--;
        }
    }
        if(t==3){
            player1score++;
            flag=1;
        }
        t=0;
        z=1;
        //diagonal up right check
        if((c+1<=m-1)&&(c+2<=m-1)&&(c+3<=m-1)&&(r-1>=0)&&(r-2>=0)&&(r-3>=0)){
            r1=r-1;
        for(c1=c+1;z<4;z++){

            if((a[r1][c1]==89)&&(a[r][c]==89)){
                t++;
            }
        r1--;
        c1++;
        }
    }
        if(t==3){
            player1score++;
          flag=1;
        }
        t=0;
        z=1;

    }

   }

   return player1score;
 }
 //-----------------
 int checkwinp2(int n,int m,int a[n][m]){
 int k=0;
int player2score=0;
 int r,c,r1,c1,z=1,t=0,flag=0;
 for(r=n-1;r>=0;r--){
        flag=0;
        z=1;
        t=0;
    for(c=0;c<m;c++){

        //side right check
        if((c+1<=m-1)&&(c+2<=m-1)&&(c+3<=m-1)){
        for(c1=c+1;z<4;z++){
            if((a[r][c1]==88)&&(a[r][c]==88)){
                t++;
            }
            c1++;
        }
    }
        if(t==3){
            player2score++;
            flag=1;
        }
        t=0;
        z=1;

        //left up diagonal check
    if((c-1>=0)&&(c-2>=0)&&(c-3>=0)&&(r-1>=0)&&(r-2>=0)&&(r-3>=0)){
            r1=r-1;
        for(c1=c-1;z<4;z++){

            if((a[r1][c1]==88)&&(a[r][c]==88)){
                t++;
            }
            c1--;
            r1--;
        }
    }
        if(t==3){
            player2score++;
          flag=1;
        }
        t=0;
        z=1;
        //up check
        if((r-1>=0)&&(r-2>=0)&&(r-3>=0)){
        for(r1=r-1;z<4;z++){
            if((a[r1][c]==88)&&(a[r][c]==88)){
                t++;
            }
            r1--;
        }
    }
        if(t==3){
            player2score++;
            flag=1;
        }
        t=0;
        z=1;
        //diagonal up right check
        if((c+1<=m-1)&&(c+2<=m-1)&&(c+3<=m-1)&&(r-1>=0)&&(r-2>=0)&&(r-3>=0)){
                r1=r-1;
        for(c1=c+1;z<4;z++){

            if((a[r1][c1]==88)&&(a[r][c]==88)){
                t++;
            }
        r1--;
        c1++;
        }
    }
        if(t==3){
            player2score++;
          flag=1;
        }
        t=0;
        z=1;

    }
    if(flag==1){

            k++;
        }
   }

   return player2score;
 }
void computermode(int n,int m,int a[n][m]){
int i1,j1,exit=0;
for(i1=n-1;i1>=0;i1--){
    for(j1=0;j1<m;j1++){
      if(a[i1][j1]==' '){
        a[i1][j1]=89;
        exit=1;
        break;
      }
    }
    if(exit==1){
        break;
    }
}
}
void saving(struct player playerxx)
{
    int flag=0;
    int s=countlines();
    if(s==0){
    FILE *save;
    save=fopen("savings_bin","ab+");
    fwrite(playerxx.name,sizeof(playerxx.name),1,save);
    fwrite(&playerxx.score,sizeof(playerxx.score),1,save);
    fclose(save);
    }
    else{
    struct player players[s];
    FILE *save;
    save=fopen("savings_bin","ab+");
    for(int i=0;!feof(save);i++){
        if(fread(players[i].name,sizeof(players[i].name),1,save)==0)break;
        fread(&players[i].score,sizeof(players[i].score),1,save);
    }
    fclose(save);
    for(int i=0;i<s;i++){
        if(strcmp(players[i].name,playerxx.name)==0){
                flag=1;
            if((players[i].score>=playerxx.score)){

            }
            else{
                players[i].score=playerxx.score;
            }
        }

    }
    FILE *saved;
    saved=fopen("savings_bin","wb");
    for(int i=0;i<s;i++){
    fwrite(players[i].name,sizeof(players[i].name),1,saved);
    fwrite(&players[i].score,sizeof(players[i].score),1,saved);
    }
    if(flag==0){
    fwrite(playerxx.name,sizeof(playerxx.name),1,saved);
    fwrite(&playerxx.score,sizeof(playerxx.score),1,saved);
    }
    fclose(saved);

    }
}
int countlines()
{
    FILE *saves;
    saves=fopen("savings_bin","ab+");
    int count=0;
    char c;
    for (c = getc(saves); c != EOF; c = getc(saves)){
        if (c == '\n'){ // Increment count if this character is newline
            count++;
            }
    }
    // Close the file
    fclose(saves);
    return count;
}
void print_high_scores()
{

    int k=countlines();
    if(k==0){
        printf("\nFile is empty or corrupted\n");
    }
    FILE *print;
    print=fopen("savings_bin","ab+");
    struct player playerss[k];
    for(int i=0;!feof(print);i++){
        if(fread(playerss[i].name,sizeof(playerss[i].name),1,print)==0)break;
        fread(&playerss[i].score,sizeof(playerss[i].score),1,print);
    }
    fclose(print);
    //sort
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(playerss[i].score>playerss[j].score){
                temp=playerss[i];
                playerss[i]=playerss[j];
                playerss[j]=temp;
            }
        }
    }

    //
    int zz=0;
    for(int i=k-1;i>=0;i--){
        printf("%s %d\n",playerss[i].name,playerss[i].score);
        zz++;
        if(zz==para.Highscore){
            break;
        }
    }
}

void xml()
{
    static int error = 0;

    char path[200] = {'0'};
    if (error == 0) // dafault file to be named "config.xml"
        strcpy(path, "config.xml");
    else
    {
        if (error <= 3) // more than three it will load default dimensions
        {
            printf("configuration file not found, Enter path: ");
            gets(path);
        }
        else // after 3 trials, program creates its own default values
        {    // default
            printf("\nIt seems that the file is not found and game will load default values");
            para.ncols = 7;
            para.nrows = 9;
            para.Highscore = 10;
            return;
        }
    }
    int i = 0, start_config, end_config, start_width, end_width, start_height, end_height, start_highscores, end_highscores, err_flag, tag_flag = 0;
    char firstconf[] = "<Configurations>", firstwidth[] = "<Width>", firstheight[] = "<Height>", highscores1[] = "<Highscores>";
    char secondconf[] = "</Configurations>", secondwidth[] = "</Width>", secondheight[] = "</Height>", highscores2[] = "</Highscores>";
    char ch, file_new[500] = {'0'};

    FILE *xmlfile;

    if ((xmlfile = fopen(path, "r")) == NULL)
    {
        error++;
        xml();
        return;
    }
    while ((ch = fgetc(xmlfile)) != EOF)
    {
        if(ch == '<')
        {
            tag_flag = 0;
        }
        else if(ch == '>')
        {
            tag_flag = 1;
        }

        if (ch != ' ' && ch != '\n' && ch != '\t' && tag_flag == 1)
        {

            // avoid \t \n and breaks
            file_new[i] = ch;
            i++;
        }
        else if(tag_flag == 0)
        {
            file_new[i] = ch;
            i++;
        }
    }
    file_new[i] = '\0'; // null character to end string

    for(int j = 0; j< i; j++)
    {
        //printf("%c", file_new[j]);
    }

    fclose(xmlfile);

    start_config = subarraystring(firstconf, file_new);
    end_config = subarraystring(secondconf, file_new);

    if (start_config == -1 || end_config == -1 || end_config < start_config)
    {
        error++;
        return xml();
    }

    start_width = subarraystring(firstwidth, file_new);
    end_width = subarraystring(secondwidth, file_new);

    int size_width = end_width - start_width + 1;

    if (start_width == -1 || end_width == -1 || end_width < start_width || end_width > end_config || start_width < start_config)
    {
        error++;
        return xml();
    }
    char width[size_width];

    ///////handle if letters are assigned between tags

    // for width

    for (int p = 0, j = start_width + 7; j < end_width; j++, p++)
    {
        err_flag = 0;
        if (isdigit(file_new[j]))
        {
            width[p] = file_new[j];
        }
        else
        {
            err_flag = 1;
            error++;
            break;
        }
    }

    if (err_flag)
    {
        return xml();
    }
    width[end_width] = '\0';

    start_height = subarraystring(firstheight, file_new); /// for getting the height value
    end_height = subarraystring(secondheight, file_new);
    int size_height = end_height - start_height + 1;

    if (start_height == -1 || end_height == -1 || end_height < start_height || end_height > end_config || start_height < start_config)
    {
        error++;
        return xml();
    }

    char height[size_height];

    // for height
    for (int p = 0, j = start_height + 8; j < end_height; j++, p++)
    {
        err_flag = 0;
        if (isdigit(file_new[j]))
        {
            height[p] = file_new[j];
        }
        else
        {
            err_flag = 1;
            error++;
            break;
        }
    }

    if (err_flag)
    {
        return xml();
    }

    height[end_height] = '\0';

    start_highscores = subarraystring(highscores1, file_new);
    end_highscores = subarraystring(highscores2, file_new);

    int size_highscores = end_highscores - start_highscores + 1;

    if (start_highscores == -1 || end_highscores == -1 || end_highscores < start_highscores || end_highscores > end_config || start_highscores < start_config)
    {
        error++;
        return xml();
    }

    char highscores[size_highscores];

    // for high scores
    for (int p = 0, j = start_highscores + 12; j < end_highscores; ++j, ++p)
    {
        err_flag = 0;
        if (isdigit(file_new[j]))
        {
            highscores[p] = file_new[j];
        }
        else
        {
            err_flag = 1;
            error++;
            break;
        }
    }
    if (err_flag)
    {
        return xml();
    }

    highscores[end_highscores] = '\0';

    if (atoi(height) < 4 || atoi(width) < 4 || atoi(highscores) < 1 || atoi(height) > 50 || atoi(width) > 50 || atoi(highscores) > 100) // convert string to number
    {
        error++;
        return xml();
    }

    para.ncols= atoi(width);
    para.nrows = atoi(height);
    para.Highscore = atoi(highscores);
}

int subarraystring(char string1[], char string2[])
{
    int counter = -1, i = 0;
    while (string2[i] != '\0')
    {
        int j = 0;
        if (string2[i] == string1[j])
        {
            int k = i;
            while (string2[k] == string1[j] && string1[j] != '\0')
            {
                k++;
                j++;
            }
            if (string1[j] == '\0')
            {
                counter = i;
            }
        }
        i++;
    }
    return counter;
}
void savecaller(int n,int m,int a[n][m])
{
    int k=countlinessave();
    k=k%3;
    if(k==0){
        save0(n,m,a);
    }
    else if(k==1){
        save1(n,m,a);
    }
    else if(k==2){
        save2(n,m,a);
    }
}


int countlinessave()
{
    FILE *saves;
    saves=fopen("savnum_bin","ab+");
    int count=0;
    char c;
    for (c = getc(saves); c != EOF; c = getc(saves)){
        if (c=='\n'){ // Increment count if this character is newline
            count++;
            }
    }
    // Close the file
    fclose(saves);
    return count;
}
void save0(int n,int m,int a[n][m])
{
    FILE *count;
    count=fopen("savnum_bin","ab+");
    fwrite("\n", sizeof(char), 1,count);
    fclose(count);
    FILE *s0;
    s0=fopen("save0.txt","w");
    fprintf(s0,"%d ",n);
    fprintf(s0,"%d",m);
    fprintf(s0,"\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fprintf(s0,"%d ",a[i][j]);
        }
    }

    fclose(s0);
}
void loaddim0(int a[2])
{
    FILE *s0;
    s0=fopen("save0.txt","r");
    if(s0==NULL){
        printf("File Doesn't exist\n");
        main();
    }
    else{
        fscanf(s0,"%d",&a[0]);
        fscanf(s0,"%d",&a[1]);
    }
    fclose(s0);
}
void load0(int n,int m,int a[n][m])
{
    int x,y;
    FILE *s0;
    s0=fopen("save0.txt","r");
    if(s0==NULL){
        printf("File doesnt exist");
    }
    else{
        fscanf(s0,"%d",&x);
        fscanf(s0,"%d",&y);
       // printf("%d",x);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fscanf(s0,"%d",&a[i][j]);
        }
    }


    }
    fclose(s0);

}
void save1(int n,int m,int a[n][m])
{
    FILE *count;
    count=fopen("savnum_bin","ab+");
    fwrite("\n", sizeof(char), 1,count);
    fclose(count);
    FILE *s0;
    s0=fopen("save1.txt","w");
    fprintf(s0,"%d ",n);
    fprintf(s0,"%d",m);
    fprintf(s0,"\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fprintf(s0,"%d ",a[i][j]);
        }
    }

    fclose(s0);
}
void loaddim1(int a[2])
{
    FILE *s0;
    s0=fopen("save1.txt","r");
    if(s0==NULL){
        printf("File Doesn't exist\n");
        main();
    }
    else{
        fscanf(s0,"%d",&a[0]);
        fscanf(s0,"%d",&a[1]);
    }
    fclose(s0);
}
void load1(int n,int m,int a[n][m])
{
    int x,y;
    FILE *s0;
    s0=fopen("save1.txt","r");
    if(s0==NULL){
        printf("File doesnt exist");
    }
    else{
        fscanf(s0,"%d",&x);
        fscanf(s0,"%d",&y);
       // printf("%d",x);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fscanf(s0,"%d",&a[i][j]);
        }
    }


    }
    fclose(s0);

}
void save2(int n,int m,int a[n][m])
{
    FILE *count;
    count=fopen("savnum_bin","ab+");
    fwrite("\n", sizeof(char), 1,count);
    fclose(count);
    FILE *s0;
    s0=fopen("save2.txt","w");
    fprintf(s0,"%d ",n);
    fprintf(s0,"%d",m);
    fprintf(s0,"\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fprintf(s0,"%d ",a[i][j]);
        }
    }

    fclose(s0);
}
void loaddim2(int a[2])
{
    FILE *s0;
    s0=fopen("save2.txt","r");
    if(s0==NULL){
        printf("File Doesn't exist\n");
        main();
    }
    else{
        fscanf(s0,"%d",&a[0]);
        fscanf(s0,"%d",&a[1]);
    }
    fclose(s0);
}
void load2(int n,int m,int a[n][m])
{
    int x,y;
    FILE *s0;
    s0=fopen("save2.txt","r");
    if(s0==NULL){
        printf("File doesnt exist");
    }
    else{
        fscanf(s0,"%d",&x);
        fscanf(s0,"%d",&y);
       // printf("%d",x);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fscanf(s0,"%d",&a[i][j]);
        }
    }


    }
    fclose(s0);

}


void selection(int *mode){
  printf("\nEnter Mode\n1.HumanvsHuman\n2.HumanvsComputer\n");
    scanf("%d",mode);
    if(*mode!=1 && *mode!=2){
        system("cls") ;
        printf("Invalid input") ;
            Sleep(2) ;
        system("cls") ;
        selection(mode) ;

    }
    }









