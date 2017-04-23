/*
 * Syntax error test 2:
 * Line 13: error in expression (rhs of an assignment)
 *
 */
public class Err2
{
    public static void main( String[] args )
    {
	int i = 0;
	int j = 0;

	j = 9 + i  8;

	return;
    }
}
