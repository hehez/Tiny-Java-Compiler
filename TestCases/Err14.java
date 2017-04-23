/*
 * Syntax error test 14: 
 * Line 10: variable declaration without a literal in initialization
 *
 */
public class Err14
{
    public static void main( String[] args )
    {
	int i = ;

	j = 9 + i * 8;

	return;
    }
}
