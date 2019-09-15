/*Holland Weaver
 COP3223, 0R06
 Project 8, 12/2/18
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    //Define Variables
    int hrs, col, row, rannum, track = 0;
    
    //Define Structures for Ninja Stats and Map Information
    struct ninja
    {
        int search;
        int stealth;
    };
    
    struct map
    {
        int searchval;
        int item;
        int found;
    };
    //Open map.txt file for Necessary Input Information
    FILE *ifp;
    ifp = fopen("map.txt", "r");
    
    struct map mapp[3][3];
    
    //Nested For Loops to Determine the Map
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            fscanf(ifp, "%d %d", &mapp[i][j].searchval, &mapp[i][j].item);
            mapp[i][j].found = 0;
        }
    }
    
    struct ninja team[4];
    
    //For Loop to Determine the Ninja's Skill Levels from the Text File
    for(int h = 0; h < 4; h++)
    {
        fscanf(ifp, "%d %d", &team[h].search, &team[h].stealth);
    }
    
    //For Loop to Track Hours of Relic Searching
    for(hrs = 2; hrs > 0; hrs--)
    {
        printf("\nYou have %d hours left to collect the relics.", hrs);
        {
            printf("\nNinja   Search   Stealth\n");
            
            //For Loop to Print the Ninja's Skill Levels from the Text File
            for(int n = 0; n < 4; n++)
            {
                printf("%d       %d        %d\n", n+1, team[n].search, team[n].stealth);
            }
            
            //For Loop to Prompt User to Input the Desired Location
            for(int p = 1; p < 5; p++)
            {
                printf("\nWhere would you like to send ninja %d?\n", p);
                
                //For Loop to Print the Map from the Text Files
                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        if(!mapp[i][j].found)
                        {
                            printf("%ds\t", mapp[i][j].searchval);
                        }
                        else
                        {
                            //Switch Statement to Determine and Print the Findings of the Searched Location
                            switch(mapp[i][j].item)
                            {
                                case 0:
                                    printf("TRAP\t");
                                    break;
                                    
                                case 5:
                                    printf("NOTHING\t");
                                    break;
                                    
                                default:
                                    printf("RELIC\t");
                                    break;
                            }
                        }
                    }
                    printf("\n");
                }
                printf("\n");
                scanf("%d %d", &row, &col);
                row--;
                col--;
                
                //Random Number Generator for a Number Between 0 - The Ninja's Stealth Level
                srand(time(NULL));
                rannum = rand() % team[p].stealth;
                //              printf("%d", rannum);
                
                //If Statement to Determine When a Ninja Gets Caught
                if(rannum == 0)
                {
                    printf("\nYour ninja has been caught!\n");
                    continue;
                }
                
                //If Statement to Determine if a Ninja Can Search a Room
                if(mapp[row][col].searchval <= team[p].search)
                {
                    mapp[row][col].found = 1;
                    
                    //Switch Statement to Determine if a Ninja Falls Into a Trap, Finds a Relic, or Finds Nothing
                    //Adds +1 to Track or Removes -1 From Stealth
                    switch(mapp[row][col].item)
                    {
                        case 0:
                            printf("\nYour ninja fell into a trap!\n");
                            team[p].stealth--;
                            break;
                            
                        case 1:
                            printf("\nYou have found the founder's KATANA.\n");
                            track++;
                            break;
                            
                        case 2:
                            printf("\nYou have found an ornate SCROLL.\n");
                            track++;
                            break;
                            
                        case 3:
                            printf("\nYou have found a JADE statue.\n");
                            track++;
                            break;
                            
                        case 4:
                            printf("\nYou have found an ancient MASK.\n");
                            track++;
                            break;
                            
                        case 5:
                            printf("\nThere is nothing in this room.\n");
                            break;
                    }
                }
                
                else
                {
                    printf("\nYour ninja was not able to search this room.\n");
                }
            }
        }
        
        //If Statement to Determine if All Relics Were Found
        if(track == 4)
        {
            printf("\nYou have retrieved all of the relics!");
            return 0;
        }
    }
    
    //Print Statement if the User Doesn't Find All Four Relics in Two Hours
    printf("\nYou are forced to leave the temple. You retrieved %d relics for the Ninja Academy!", track);
    return 0;
    
    
}
//
//  Program8.c
//  
//
//  Created by Holland Weaver on 12/2/18.
//

#include <stdio.h>
