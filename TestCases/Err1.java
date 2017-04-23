/*
 * Syntax error test 1: 
 * Line 9: variable declaration without initialization
 *
 */
public class Err1
{
    public static void main( String[] args )
    {
	int i;

	j = 9 + i * 8;

	return;
    }
}
