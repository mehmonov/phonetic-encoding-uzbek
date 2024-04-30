def isvowel(c):
    return c.upper() in ['A', 'E', 'I', 'O', 'U']

def encode(word):
    s = word.upper()
    len_s = len(s)
    pos = 0
    result = ""
    while pos < len_s:
        c = s[pos]
        next_c = s[pos + 1] if pos < len_s - 1 else ''
        nextnext = s[pos + 2] if pos < len_s - 2 else ''
        if c == 'C':
            if next_c == 'H':
                result += 'J'
                pos += 1
            else:
                result += 'S'
        elif c == 'A':
            if pos == 0 or pos == len_s - 1:
                result += 'A'
            elif next_c == 'O':
                result += 'O'
                pos += 1
            elif next_c == 'I':
                result += 'Y'
                pos += 1
        elif c == 'E':
            if pos == 0 or pos == len_s - 1:
                result += 'I'
        elif c == 'I':
            if pos == 0:
                result += 'I'
            elif next_c in ['A', 'O']:
                result += 'Y'
                pos += 1
        elif c == 'O':
            if pos == 0:
                if next_c == '\'':
                    result += 'U'
                    pos += 1
                elif next_c == 'I':
                    result += 'O'
                    result += 'Y'
                    pos += 1
                else:
                    result += 'O'
            elif next_c == 'I':
                result += 'Y'
                pos += 1
            elif pos == len_s - 1:
                result += 'O'
        elif c in ['B', 'P']:
            result += 'P'
            if next_c == c:
                pos += 1
        elif c in ['F', 'V']:
            result += 'F'
            if next_c == c:
                pos += 1
        elif c == 'D':
            result += 'T'
            if next_c == c:
                pos += 1
        elif c in ['Q', 'K']:
            result += 'K'
            if next_c == c:
                pos += 1
        elif c == 'G':
            result += 'K'
            if next_c == '\'':
                pos += 1
            elif next_c == c:
                pos += 1
        elif c in ['H', 'X']:
            result += 'X'
            if next_c == 'T' and not isvowel(nextnext):
                pos += 1
            elif next_c == c:
                pos += 1
        elif c == 'J':
            result += 'J'
            if next_c == c:
                pos += 1
        elif c in ['L', 'M', 'N', 'R']:
            result += c
            if next_c == c:
                pos += 1
        elif c == 'S':
            result += 'S'
            if next_c == 'H' or next_c == c:
                pos += 1
        elif c == 'T':
            if next_c == 'S':
                result += 'S'
                pos += 1
            else:
                result += 'T'
                if next_c == c:
                    pos += 1
        elif c == 'U':
            if pos == 0 or pos == len_s - 1:
                result += 'U'
        elif c == 'Y':
            if pos > 0 and next_c in ['A', 'U', 'O', 'E']:
                result += next_c
                pos += 1
            else:
                result += 'Y'
                if next_c == c:
                    pos += 1
        elif c == 'Z':
            result += 'S'
            if next_c == c:
                pos += 1
        elif c == ' ':
            result += ' '
            if next_c == c:
                pos += 1
        pos += 1
    return result

