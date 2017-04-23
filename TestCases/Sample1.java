/*
 * Sample program 1
 */
public class Sample1
{
    public static void main( String[] args )
    {
	int i = 0;
	int j = 0;

	i = SimpleIO.readInt();                // get i 
	j = 9 + i * 8;                         // evaluate j 
	SimpleIO.printString( "Result is " );  // print the label
	SimpleIO.printInt( j );                // print j 
	SimpleIO.println();                    // print the newline
	return;
    }
}
