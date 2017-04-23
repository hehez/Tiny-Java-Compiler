/*
 * Syntax error test 3:
 * Line 8: field declaration without initialization
 *
 */
public class Err3
{
    static int field;

    public static void main( String[] args )
    {
	int i = 0;
	int j = 0;

	j = 9 + i * 8;

	return;
    }
}
