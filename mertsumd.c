#include <stdio.h>
#define maxexp 8

int main() {
  int power=1,i,n,temp,factor,next,mobius,count,mertens=0,ZP=0,k,power2,b,sum,tempb,factorb,term,elatt=0,afth=0,l;
  for (i=1;i<=maxexp;i++)          /*exw arxikopoihsei to power=1 afoy einai to oydetero stoixeio toy pollaplasiasmoy*/
  {
    power*=10;                     /*briskw to 10 eis thn maxexp*/
  }
  for (n=1;n<=power+9;n++)         /*briskw tis times ths mertens gia kathe n sto diasthma 1 ews 10 eis thn maxexp*/
  {
    count=0;                      /* arxizw na metraw to plhthos twn prwtwn paragontwn tou n, to arxikopoiw 0*/
    if (n%4 ==0 || n%9==0)        /* an o n einai pollaplasio toy 4 h toy 9 einai sigoura oxi square free */
    {
      mobius=0;                   /* an oxi square free tote h mobius einai 0 */
    }
    else
    {
      temp=n;                     /*fylaw to n sto temp giati thelw na kanw prakseis me to n xwris na metablhthei omws telika */
      if (temp%2==0)              /* an o arithmos einai to 2 thelw na apallagw eksarxhs, na mhn xreiastei na mpw sto while*/
      {
        temp/=2;
        count+=1;                 /* afoy to 2 diairei akribws to n, ara brhkame 1 prwto paragonta toy n*/
      }
      if (temp%3==0)              /*same gia to 3*/
      {
        temp/=3;
        count+=1;
      }
      factor=5;                   /*ara o epomenos prwtos poy tha eleksw an einai paragontas toy n einai to 5*/
      next=0;                     /*i use ayth th logikh metablhth gia na kserw an bghka apo to while biaia logw break h oxi*/
      while (factor*factor<=temp) /*psaxnw gia diairetes mexri th riza tou n*/
      {
        if (temp%factor==0)       /*elenxw an o trexwn factor einai diaireths toy n */
        {  
          count+=1;               /*an einai ayksanw plhtos prwtwn paragontwn*/
          temp/=factor;           /* kai diairw to temp me to factor gia na parw to phiko*/
          if (temp%factor==0)     /* an o trexwn factor einai ksana diaireths toy n tote einai oxi square free*/
          {
            next=1;               /*metaballw th logikh metablhth gia na kserw oti bgainw apo to while biaia logw ths break*/
            count+=1;
            break;                /*spaw teleiws thn epanalhpsh,afoy katalaba apo twra oti oxi square free*/
          }
        }
        if (factor%6==5)          /*meta to 5 oi epomenoi factors poy elegxw einai ta zeygarakia stis eksades,arkei ayto*/
        {
          factor+=2;              /*an briskomai ston prwto oro toy zeygarioy paw sto methepomeno*/
        }
        else if (factor%6==1)
        {
          factor+=4;              /*an briskomai ston deytero paw sto prwto toy epomenoy zeygarioy*/
        } 
      }
      if (temp!=1 )               /*an to temp den einai 1, shmainei oti exei perisepsei enas teleytaios prwtos paragontas, px an n=11*/
      {
        count+=1;
      }
      if (next==1)               /*an bghka biaia logw ths break shmainei oti o arithmos einai oxi square free*/
      {
        mobius=0;                /*afou to n den einai sqf*/
      }
      else 
      {
        if (count%2==0)          /* afoy einai sqf prepei na eleksw pl prwtwn paragontwn*/
        {
          mobius=1;              /*an square free kai artio plhthos prwtwvn paragontwn tote h mobius ginetai 1*/
        }
        else
        {
          mobius=-1;             /*an square free kai peritto plhthos prwtwvn paragontwn tote h mobius ginetai -1*/
        }
        mertens+=mobius;         /*prosthetw sthn mertens thn timh ths mobius gia to trexwn n*/
      }  
    }
    if (mertens==0)              /*an h mertens isoytai me to 0 tote ayksanw kata 1 ta mhdenika ths shmeia*/
    {
      ZP+=1;
    }
    for (k=1;k<=maxexp;k++)          
    {
      power2=1;                  /*ksekinaw thn diadikasia gia na brw to 10 eis thn k*/
      for (l=1;l<=k;l++)
      {
        power2*=10;    
      }
      if(n>=(power2-9) && n<=(power2+9))
      {
        if (n==power2-9 && n!=1)  /*otan allazei h dynamh toy 10 (ektos an eimaste sthn prwth fora) tote ektypwnontai telitses prin ektypwthei h mertens*/
        {
          printf("\n..........");
        }
        printf("\n M(%d) = %d",n,mertens);
        break;
      }
    }  
  }
  printf("\n\n Found %d zero points of the Mertens Function\n",ZP); 
  printf ("\n Checking numbers in the range [2,%d]\n",ZP*1000);
  /*loipon twra...
  estw oti s(N) to sum olwn twn diaretwn toy N
  yparxei ena mathimatiko thewrhma pou leei oti an o N paragontopoihtei ws ekshs
  N=p1^e1+p2^e2+p3^e3+...+pk^ek ,opoy pi prwtos kai ei>=1 tote
  s(N)= (1+p1+p1^2+...+p1^e1)*(1+p2+p2^2+...+p2^e2)*(1+pk+pk^2+...+pk^ek)
  kai afoy twra thelw na brw toys perfect,abundant and defficient numbers prepei na 
  brw to sum twn kanonikwn toys diairetwn alla tha to brw ws to parapanw ginomeno giati faster*/
  for (b=2;b<=ZP*1000;b++)          /*ayto to diasthma zhtaei h ekfwnhsh*/
  {
    sum=1;                          /*o oydeteros oros toy pollaplasiasmoy poy ginetai sthn s(N)*/
    tempb=b;                        /*fylaw to b sto tempb giati thelw na kanw prakseis me to b xwris na metablhthei omws telika */
    factorb=2;                      /*the first prwtos arithmos pou tha eleksw einai to 2 */
    while (factorb*factorb<=tempb)  /*elenxw gia diairetes mexri th riza*/
    {
      term=1;                       /*oydeteros oros toy pollaplasiasmoy*/
      while (tempb%factorb==0)      /*oso to factorb einai diaireths toy b mpainw sth while*/
      {
        term=factorb*term+1;        /*ftaxnw gia kathe factor thn parenthesh (1+pk+pk^2+...+pk^ek)*/
        tempb/=factorb;             /* kai diairw to tempb me to factorb gia na parw to phiko*/
      }
      sum*=term;                    /*pollaplasiazw etsi swte na ftiaksw thn parastash ths s(N)*/
      if (factorb==2)               /*apo edw kai katw proetoimazw thn epomenh timh toy factor me thn idia logikh me prin*/
      {
        factorb=3;
      }
      else if (factorb ==3)
      {
        factorb=5;
      }
      else if (factorb %6==5)
      {
        factorb+=2;
      }
      else
      {
        factorb+=4;
      }
    }
    if (tempb!=1)                /*an o b exei ton megalytero prwto toy paragonta ypsomeno se dynamh tote sto telos tha exei perisepsei*/
    {
      sum*=(1+tempb);            /*einai o teleytaios paragontas toy arithoy se prwth dynamh, ara h teleytaia parethensh tha einai ayth*/
    }
    if (sum-b==b)                /*h s(N) ypologizei to athroisma olwn twn diairetwn toy n mazi kai ton eayto toy alla gia na elenxw an 
                                 einai perfect abundant or defficient thelw to athroisma mono twn kanonikwn diairetwn toy n */
    {
      printf("\n Found perfect number: %d",b);
    }
    else if (sum-b<b)            /*apo orismo defficient*/
    {
      elatt+=1;
    }
    else if (sum-b>b)            /*apo orismo abundant*/
    {
      afth+=1;
    }
  }
 printf("\n\n Found %d defficient numbers",elatt);
 printf("\n Found %d abundant numbers ",afth); 
}
