using System.Text;


string Encode(string word)
{
    string s = word.ToUpper();

    int len = s.Length;
    int pos = 0;

    StringBuilder result = new StringBuilder();

    while (pos < len)
    {
        char c = s[pos];
        char next = pos < len - 1 ? s[pos + 1] : char.MinValue;
        
        switch (c)
        {
           
            case 'C':
                if (next == 'H')
                {
                    result.Append("J");
                    pos++;
                }
                else
                {
                    result.Append("S");
                }
                break;
            
           
            case 'A':
                if (pos == 0 || pos == len - 1) 
                    result.Append("A");
                else if (next == 'O')
                {
                    result.Append('O');
                    pos++;
                }
                else if (next == 'I')
                {
                    result.Append('Y');
                    pos++;
                }
                break;

            case 'E':
                if (pos == 0 || pos == len - 1) result.Append("I");
                break;

            case 'I':
                if (pos == 0) 
                    result.Append("I");
                else if (next == 'A' || next == 'O')
                {
                    result.Append("Y");
                    pos++;
                }
                break;

            
            case 'O':
                if (pos == 0)
                {
                    if (next == '\'')
                    {
                        result.Append("U");
                        pos++;
                    }
                    else if (next == 'I')
                    {
                        result.Append("OY");
                        pos++;
                    }
                    else
                    { 
                        result.Append("O");
                    }
                }
                else if (next == 'I')
                {
                    result.Append("Y");
                    pos++;
                }
                else if (pos == len - 1)
                {
                    result.Append("O");
                }
                break;

            case 'B':
            case 'P':
            case 'F':
            case 'V':
                result.Append("P");
                if (next == c) pos++;
                break;

            case 'D':
                result.Append("T");
                if (next == c) pos++;
                break;

            
            case 'Q':
            case 'K':
                result.Append("K");
                if (next == c) pos++;
                break;

            case 'G':
                result.Append("K");
                if (next == '\'')
                {
                    pos++;
                }
                else if (next == c) pos++;
                break;

            case 'H':
            case 'X':
                result.Append("X");
                if (next == c) pos++;
                break;

            case 'J':
                result.Append("J");
                if (next == c) pos++;
                break;

            case 'L':
                result.Append(c);
                if (next == c) pos++;
                break;

            case 'M':
                result.Append(c);
                if (next == c) pos++;
                break;

            case 'N':
                result.Append(c);
                if (next == 'G' && pos == len - 2) 
                    pos++;
                else if (next == c) pos++;
                break;

            case 'R':
                result.Append(c);
                if (next == c) pos++;
                break;

            case 'S':
                result.Append("S");
                if (next == 'H' || next == c) pos++;
                break;

            case 'T':
                if (next == 'S')
                {
                    result.Append("S");
                    pos++;
                }
                else
                {
                    result.Append("T");
                    if (next == c) pos++;
                }
                break;

            case 'U':
                if (pos == 0 || pos == len - 1) result.Append("U");
                break;

            case 'Y':
                if (pos > 0 && (next == 'A' || next == 'U' || next == 'O' || next == 'E'))
                {
                    result.Append(next);
                    pos++;
                }
                else
                {
                    result.Append("Y");
                    if (next == c) pos++;
                }
                break;

            case 'Z':
                result.Append("S");
                if (next == c) pos++;
                break;

        }
        pos++;
    }

    return result.ToString();
}