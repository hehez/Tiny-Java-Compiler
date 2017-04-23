/*
 * Syntax error test 11:
 * Line 14: incorrect method call (no closing ')' paren)
 *
 */
public class Err11
{

    public static void main( String[] args )
    {
	int i = 0;
	int sum = 0;
 
	i = SimpleIO.readInt(;

	return;
    }
}
