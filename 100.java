import java.io.*;
import java.util.*;

class Main
{
    static String ReadLn (int maxLg)  // utility function to read from stdin
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }

    public static void main (String args[])  // entry point from OS
    {
        Main myWork = new Main();  // create a dinamic instance
        myWork.Begin();            // the true entry point
    }

    void Begin()
    {
        String input;
        StringTokenizer idata;
       
        Integer lowernum , uppernum , firstnum, secondnum,maxnumberofcycles ;
        
        while ((input = Main.ReadLn (255)) != null)
        {
        	idata = new StringTokenizer (input);
        	firstnum = Integer.parseInt (idata.nextToken());
        	secondnum = Integer.parseInt (idata.nextToken());
        	
			lowernum = Math.min(firstnum, secondnum);
			uppernum = Math.max(firstnum, secondnum);
			
			Integer n;
			Integer numberofcycles, index;
			Integer array[] = new Integer[uppernum - lowernum + 1];
			
			maxnumberofcycles = 0;
			while (lowernum <= uppernum) {
				n = lowernum;
				index = 0;
				numberofcycles = 1;
				while (n != 1) {
					if (n % 2 == 1) {
						n = 3 * n + 1;
					} else {
						n = n / 2;
					}
					numberofcycles++;					
				}
				lowernum++;
				array[index] = numberofcycles;				
				if (array[index] > maxnumberofcycles) {
					maxnumberofcycles = array[index];
				}				
				index++;
			}			
			System.out.println(""+firstnum+" "+secondnum+" "+maxnumberofcycles);
        }
    }
}
