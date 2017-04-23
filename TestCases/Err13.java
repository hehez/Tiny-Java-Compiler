/*
 * Syntax error test 13:
 * Line 14: incorrect statement -- just an identifier
 *
 */
public class Err13
{

    public static void main( String[] args )
    {
	int i = 0;
	int sum = 0;
 
	sum;

	return;
    }
}
