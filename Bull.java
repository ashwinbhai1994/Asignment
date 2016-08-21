/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author bharadwaj
 */
public class JavaApplication2 {

 

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String name;
        String pat;
        int bull=0;
        int cow=0;
        String temp_name;
        String temp_pat;
        Scanner s=new Scanner(System.in);
        name="hate";
        int fl=0;
        while(true)
        {
            pat=s.nextLine();
            char patten[]=pat.toCharArray();
            bull=0;
            cow=0;
            temp_pat=pat;
            if(name.equals(pat)==true)
            {
                System.out.println("Great work");
                break;
            }
            else
            {
                for(int i=0;i<name.length();i++)
                {
                    if(name.charAt(i)=='8')
                    {
                        continue;
                    }
                    if(name.charAt(i)==patten[i])
                    {
                        bull++;
                        patten[i]='8';
                    }
                }
                for(int i=0;i<name.length();i++)
                {
                    fl=someWhere(name,patten,i);
                    
                    if(fl==1)
                    {
                        cow++;
                    }
                }
                System.out.println("bull "+bull+" cow "+cow);
                
            }
            
        }
    }

    private static int someWhere(String name,char[] patten, int n) {
int i=0;
int fp=0;
char sp=patten[n];
char ch;

if(sp=='8')
{
   
    return 0;
}
if(patten[n]==name.charAt(n))
      {
          return 0;
      }
for(i=0;i<patten.length;i++)
{
      if( patten[i]!='8')
      {
          
          ch=name.charAt(i);
          if(ch==sp)
          {
              fp=1;
              patten[i]='8';
              break;
          }
      }
}
    if(fp==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    }
}
