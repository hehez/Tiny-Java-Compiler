/*
 * Syntax error test 10: 
 * Line 14: statement beginning with 'else'
 *
 */
public class Err10
{
    public static void main( String[] args )
    {
	int i = 0;
	int j = 0;

	i = 3;
	else j = 11;

	return;
    }
}
