/*
 * Syntax error test 12:
 * Line 14: incorrect method call (error in argument expression)
 *
 */
public class Err12
{

    public static void main( String[] args )
    {
	int i = 0;
	int sum = 0;
 
	i = SimpleIO.printInt( i sum );

	return;
    }
}
