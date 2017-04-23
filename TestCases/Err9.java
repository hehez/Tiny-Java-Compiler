/*
 * Syntax error test 9: 
 * Line 13: incorrect assignment stmt (missing rhs expression)
 *
 */
public class Err9
{
    public static void main( String[] args )
    {
	int i = 0;
	int j = 0;

	j = ;

	return;
    }
}
