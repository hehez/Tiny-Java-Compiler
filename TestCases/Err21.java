/*
 * Syntax error test 21 (grad only): 
 * Line 8:  incorrect array field declaration
 *
 */
public class Err21
{
    int[ vector = null;

    public static void main( String[] args )
    {
	vector = new int[ 10 ];
	return;
    }
}
