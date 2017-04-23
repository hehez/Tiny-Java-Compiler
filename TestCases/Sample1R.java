public class Sample1R
{
    public static void main( String[] args )
    {
	float x = 0.0f;
	float z = 0.0f;
	int   y = 0;


	x = SimpleIO.readFloat();          // read x
	z = 9 + x * 8;                     // assign to z (mixed types)
	y = (int) (9 + x * 8);             // assign to y with a cast

	SimpleIO.printString( "Result (int) is " );
	SimpleIO.printInt( y );            // print y
	SimpleIO.println();                // print newline
	SimpleIO.printString( "Result (float) is " );
	SimpleIO.printFloat( z );          // print z 
	SimpleIO.println();                // print newline
	return;
    }
}
