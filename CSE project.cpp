#include<stdio.h>
#include<stdlib.h>

struct batsman
 {
	char name[25];
	int runs,score,balls,toruns,tobal,ones,twos,threes,fours,sixes;
	int max_six,max_run,max_four;
	float str;

 }pl1[100],pl3;


struct bowler
 {
	char name[25];
	int runsgv,wkttkn,overs;
	int max_w;
	float econ;
 }pl2[100],pl4;


int main()
{
 int plno,choice;
  int a,f,e;
  printf("Enter the Batsman detail:\n");
  printf("Enter the number of  batsman:\n");
  scanf("%d",e);
  for(a=0;a<e;a++)
   {
		
	   printf("Enter name batsman%d:\n",a+1);
	   scanf("%s",pl1[a].name);
		
		
       printf("Enter the number of ones scored by player%d:\n",a+1);
	   scanf("%d",&pl1[a].ones);
		
		
       printf("Enter the number of twos scored by player%d:\n",a+1);
       scanf("%d",&pl1[a].twos);
		
		
	   printf("Enter the number of threes scored by player%d:\n",a+1);
	   scanf("%d",&pl1[a].threes);
		
		
	   printf("Enter the number of fours scored by player:%d\n",a+1);
	   scanf("%d",&pl1[a].fours);
		
		
	   printf("Enter the number of sixes scored by the player:\n",a+1);
	   scanf("%d",&pl1[a].sixes);
		
		
	   printf("Enter the balls played by the player%d:\n",a+1);
	   scanf("%d",&pl1[a].balls);
	}
	
	
	
	printf("\nEnter the blowers details:\n");
	
	printf("Enter the number of bowlers:\n");
	
	scanf("%d",&f);
	
	
	for(a=0;a<f;a++);
	{
		
		printf("\nEnter name of bowler%d:",a+1);
		scanf("%s",&pl2[a].name);
		
		
		printf("Enter the runs given by the bowler%d:\n",a+1);
		scanf("%d",&pl2[a].runsgv);
		
		
		printf("Enter the overs bowled by the bowler%d:\n",a+1);
		scanf("%d",&pl2[a].overs);
		
		
		printf("Enter the wickets taken by the bowler%d:\n",a+1);
		scanf("%d",&pl2[a].wkttkn);
		
	}
	
	printf("Thank you all details are recorded\n");
	
	
	do
	 {
			
		printf("Enter the choice:\n 1)Batsman detail:\n 2)Bowlers detail:\n 3)Match summary:\n 4)Record:\n 5)Exit\n ");
		scanf("%d",&choice);
			
	 switch(choice)
	  {
				
		case1:
		     printf("Enter the batsman number to see his details\n");
		     scanf("%d",&plno);
					
			 plno--;
			 printf("            Player Detail\n            ");
			 printf("========================================================================================================================================================================================\n");
			 printf("    Batsman                runs                         balls                     fours                                    sixes                                        sr \n            ");	
			 printf("==========================================================================================================================================================================================\n");
				
				
				pl1[plno].runs=(1*pl1[plno].ones)+(2*pl1[plno].twos)+(3*pl1[plno].threes)+(4*pl1[plno].fours)+(6*pl1[plno].sixes);
				pl1[plno].str=(pl1[plno].runs*100.00)/pl1[plno].balls;
				printf(" %-15s %-14d %-13d %-11d %-11 %9.2f\n\n",pl1[plno].name,pl1[plno].runs,pl1[plno].fours,pl1[plno].sixes,pl1[plno].str);
				
				break;
				
				
				case 2:
				printf("Enter bowlers number to see his details\n");
				scanf("%d",&plno);
				
				plno--;
				printf("			Player detail\n ");
				printf("==========================================================================================================================================================================================\n");
				printf("Bowler		overs		runs		wicket		economy\n");
				printf("==========================================================================================================================================================================================\n");
				
				for(a=0;a<f;a++)
				{ pl2[plno].econ=pl2[plno].runsgv/pl2[plno].overs;
				  printf(" %-15s %-14d %-13d %-11d %-11.2f\n\n",pl2[plno].name,pl2[plno].overs,pl2[plno].runsgv,pl2[plno].wkttkn,pl2[plno].econ);
				}
				
				break;
				
				case 3:
					printf("					Match summary\n");
					printf("=======================================================================================================================================================================================\n");
					printf(" Batsman		runs		balls		fours		sixes		sr                                                                                             \n");
					printf("=======================================================================================================================================================================================\n");
					
					for(a=0;a<1;a++)
					{
						pl1[a].runs=(1*pl1[a].ones)+(2*pl1[a].twos)+(3*pl1[a].threes)+(4*pl1[a].fours)+(6*pl1[a].sixes);
						pl3.toruns+=pl1[a].runs;
						pl1[a].str=(pl1[a].runs*100.00)/pl1[a].balls;
						printf(" %-15s %-14d %-13d %-11d %-11d %-9.2f\n\n",pl1[a].name,pl1[a].runs,pl1[a].balls,pl1[a].fours,pl1[a].sixes,pl1[a].str);
					}
					printf("TOTAL RUNS:%d\n\n",pl3.toruns);
					printf("\n\n");
					printf("=======================================================================================================================================================================================\n");
					printf(" Bowler		overs		runs		wicket		economy\n");
					printf("=======================================================================================================================================================================================\n");
					
					for(a=0;a<e;a++)
					{ pl2[a].econ=pl2[a].runsgv/pl2[a].overs;
					  printf(" %-15s %-14d %-13d %-11d %-11.2f\n\n\n",pl2[a].name,pl2[a].overs,pl2[a].runsgv,pl2[a].wkttkn,pl2[a].econ);
					}
					
					
					break;
					
					case 4: pl3.max_run=0,pl4.max_w=0,pl3.max_four=0,pl3.max_six=0;
					
					for(a=0;a<e;a++)
					{
						pl1[a].runs=(1*pl1[a].ones)+(2*pl1[a].twos)+(3*pl1[a].threes)+(4*pl1[a].fours)+(6*pl1[a].sixes);
						if(pl3.max_run<pl1[a].runs)
						{
							pl3.max_run=pl1[a].runs;
							
						}
					
					if(pl3.max_six<pl1[a].sixes)
					{
						pl3.max_six=pl1[a].sixes;
					}
					
					if(pl3.max_four<pl1[a].fours)
					{
						pl3.max_four=pl1[a].fours;
					}
					
					if(pl4.max_w<pl2[a].wkttkn)
					 {
						pl4.max_w=pl2[a].wkttkn;
					 }
				}
				printf("Highest runs scored by the batsman:%d\n",pl3.max_run);
				
				printf("Maximum fours scored by the batsman:%d\n",pl3.max_four);
				
				printf("Maximum sixes scored by the batsman%d:\n",pl3.max_six);
				
				printf("Maximum wickets taken by the bowler:%d\n",pl4.max_w);
				
				break;
				
				
				
				case 5:
					exit(1);
					
					default:
						printf("Enter the correct choice\n");
						break;
			
			}
			
			}while(choice!=5);
			
			
			return 0;

}
