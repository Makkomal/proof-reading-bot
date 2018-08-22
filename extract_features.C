#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <ctype.h>

void remove_punct_and_make_lower_case(char *p);

int main()
{

	char *isnull;
	FILE *fptr;
	FILE *f;
    char file[15];
	int i=0;
	char line[5000];
	char* string[5000];         //extracting lines
	char* words[5000];         //extracting words
	char* word[5000];         //extracting tokens
	char str[50];
	int nolines=0;     //number of lines in a document
	int nowords=0;    //total number of words in the document
	int noword=0;      ////number of words in the document after removing stopwords
	int j=0;                    //counter for words
	int m,k,q,z;
	int p;
	double hash[2000];           //for storing hash values

  char* stopword[]= {"a", "about", "above", "above", "across", "after", "afterwards", "again", "against", "all", "almost", "alone", "along", "already", "also","although","always","am","among", "amongst", "amoungst", "amount", "an", "and", "another", "any","anyhow","anyone","anything","anyway", "anywhere", "are", "around", "as", "at", "back","be","became", "because","become","becomes", "becoming", "been", "before", "beforehand", "behind", "being", "below", "beside", "besides", "between", "beyond", "bill", "both", "bottom","but", "by", "call", "can", "cannot", "cant", "co", "con", "could", "couldnt", "cry", "de", "describe", "detail", "do", "done", "down", "due", "during", "each", "eg", "eight", "either", "eleven","else", "elsewhere", "empty", "enough", "etc", "even", "ever", "every", "everyone", "everything", "everywhere", "except", "few", "fifteen", "fify", "fill", "find", "fire", "first", "five", "for",
		              "former", "formerly", "forty", "found", "four", "from", "front", "full", "further", "get", "give", "go", "had", "has", "hasnt", "have", "he", "hence", "her", "here", "hereafter", "hereby", "herein", "hereupon", "hers", "herself", "him", "himself", "his", "how", "however", "hundred", "ie", "if", "in", "inc", "indeed", "interest", "into", "is", "it", "its", "itself", "keep", "last", "latter", "latterly", "least", "less", "ltd", "made", "many", "may", "me", "meanwhile", "might", "mill", "mine", "more", "moreover", "most", "mostly", "move", "much", "must", "my", "myself", "name", "namely", "neither", "never", "nevertheless", "next", "nine", "no", "nobody", "none", "noone", "nor", "not", "nothing", "now", "nowhere", "of", "off", "often", "on", "once", "one", "only", "onto", "or", "other", "others", "otherwise", "our", "ours", "ourselves", "out", "over", "own","part", "per", "perhaps",
					  "please", "put", "rather", "re", "same", "see", "seem", "seemed", "seeming", "seems", "serious", "several", "she", "should", "show", "side", "since", "sincere", "six", "sixty", "so", "some", "somehow", "someone", "something", "sometime", "sometimes", "somewhere", "still", "such", "system", "take", "ten", "than", "that", "the", "their", "them", "themselves", "then", "thence", "there", "thereafter", "thereby", "therefore", "therein", "thereupon", "these", "they", "thickv", "thin", "third", "this", "those", "though", "three", "through", "throughout", "thru", "thus", "to", "together", "too", "top", "toward", "towards", "twelve", "twenty", "two", "un", "under", "until", "up", "upon", "us", "very", "via", "was", "we", "well", "were", "what", "whatever", "when", "whence", "whenever", "where", "whereafter", "whereas", "whereby", "wherein", "whereupon", "wherever", "whether", "which", "while",
					  "whither", "who", "whoever", "whole", "whom", "whose", "why", "will", "with", "within", "without", "would", "yet", "you", "your", "yours", "yourself", "yourselves", "the"};
	
	printf("Enter the filename to be opened \n");
    scanf("%s", file);

    fptr=fopen(file,"r");

    if (fptr == NULL)
    {
	printf("Cannot open file \n");
	exit(0);
    }


   while(fgets(line, sizeof(line), fptr)!=NULL){									 //extracting line by line

		if ((isnull=strchr(line, '\n')) != NULL)
		  { *isnull='\0'; }

		string[i]=strdup(line);
		i++;
		nolines++;
		}


	 for (i=0 ; i<nolines; i++) {												 //extracting word by word

		char *p= strtok(string[i]," ");
		while(p!=NULL){
		       words[j++]=p;
		       nowords++;
		       p=strtok(NULL," ");
	       }
	    }

		 for(i=0;i<nowords;i++) {
		remove_punct_and_make_lower_case(words[i]);												//conversion to lower case
				      }
				      
       printf("Total number of words in the document:%d\n",nowords);
        
	 for(i=0;i<nowords;i++) {														//removal of stopwords
	   for(k=0;k<319;k++){
		     if(strcmp(words[i],stopword[k])==0){
			 words[i]="0";
			 break; }
			 }
			}
			
		 z=0;
		 for(i=0;i<nowords;i++) {

		     if(strcmp(words[i],"0")!=0){
		     word[z]=words[i];
			z++;
			noword++;}
			}
			
			printf("Number of words remaining after removal of stopwords:%d\n",noword);

	       for(i=0;i<100;i++)
	       {hash[i]=0;}


	  p=5;
	  for(i=0;i<noword;i++)											//calculating hash values
	  {
		strcpy(str,word[i]);
		m=strlen(str);

	      for(k=1;k<=m;k++)
		  {
	   		q=(int)str[k-1];
			hash[i]=hash[i]+(q*pow(p,m-k));
			}
		}

		 for(i=0;i<noword;i++) {
		 
		 	printf("%s\n",word[i]);
		 }
		 
        printf("Hash Values Calculated\n\nEnter the filename where hash values are to be saved \n");
    	scanf("%s", file);


	       f = fopen(file,"w");
	    
	   	   for(k = 0; k < noword; k++ )											//writing to file
			{
			fprintf(f, "%0.2lf\n", hash[k]);  
			}
			printf("Done!");
	       fclose(f);
		fclose(fptr);
		return 0;
}


void remove_punct_and_make_lower_case(char *p)
{
    char *src = p, *dst = p;

    while (*src)
    {
       if (ispunct(*src))
       {
          /* Skip this character */
          src++;
       }
       else if (isupper(*src))
       {
          /* Make it lowercase */
          *dst++ = tolower(*src);
          src++;
       }
       else if (src == dst)
       {
          /* Increment both pointers without copying */
          src++;
          dst++;
       }
       else
       {
          /* Copy character */
          *dst++ = *src++;
       }
    }

    *dst = 0;
}
