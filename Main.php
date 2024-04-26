<?php

function isvowel($c) {
    return in_array(strtoupper($c), ['A','E','I','O','U']);
}

function encode($word) {
    $s = strtoupper($word);
    $len = strlen($s);
    $pos = 0;

    $result = "";
    $resultPos = 0;

    while ($pos < $len) {
        $c = $s[$pos];
        $next = $pos < $len - 1 ? $s[$pos + 1] : '';
        $nextnext = $pos < $len - 2 ? $s[$pos + 2] : '';

        switch ($c) {
            case 'C':
                if ($next == 'H') {
                    $result .= 'J';
                    $pos++;
                } else {
                    $result .= 'S';
                }
                break;

            case 'A':
                if ($pos == 0 || $pos == $len - 1) {
                    $result .= 'A';
                } else if ($next == 'O') {
                    $result .= 'O';
                    $pos++;
                } else if ($next == 'I') {
                    $result .= 'Y';
                    $pos++;
                }
                break;

            case 'E':
                if ($pos == 0 || $pos == $len - 1) {
                    $result .= 'I';
                }
                break;

            case 'I':
                if ($pos == 0) {
                    $result .= 'I';
                } else if ($next == 'A' || $next == 'O') {
                    $result .= 'Y';
                    $pos++;
                }
                break;

            case 'O':
                if ($pos == 0) {
                    if ($next == '\'') {
                        $result .= 'U';
                        $pos++;
                    } else if ($next == 'I') {
                        $result .= 'O';
                        $result .= 'Y';
                        $pos++;
                    } else {
                        $result .= 'O';
                    }
                } else if ($next == 'I') {
                    $result .= 'Y';
                    $pos++;
                } else if ($pos == $len - 1) {
                    $result .= 'O';
                }
                break;

            case 'B':
            case 'P':
                $result .= 'P';
                if ($next == $c) $pos++;
                break;

            case 'F':
            case 'V':
                $result .= 'F';
                if ($next == $c) $pos++;
                break;

            case 'D':
                $result .= 'T';
                if ($next == $c) $pos++;
                break;

            case 'Q':
            case 'K':
                $result .= 'K';
                if ($next == $c) $pos++;
                break;

            case 'G':
                $result .= 'K';
                if ($next == '\'') {
                    $pos++;
                } else if ($next == $c) {
                    $pos++;
                }
                break;

            case 'H':
            case 'X':
                $result .= 'X';
                if ($next == 'T' && !isvowel($nextnext)) {
                    $pos++;
                } else if ($next == $c) {
                    $pos++;
                }
                break;

            case 'J':
                $result .= 'J';
                if ($next == $c) $pos++;
                break;

            case 'L':
            case 'M':
            case 'N':
            case 'R':
                $result .= $c;
                if ($next == $c) $pos++;
                break;

            case 'S':
                $result .= 'S';
                if ($next == 'H' || $next == $c) $pos++;
                break;

            case 'T':
                if ($next == 'S') {
                    $result .= 'S';
                    $pos++;
                } else {
                    $result .= 'T';
                    if ($next == $c) $pos++;
                }
                break;

            case 'U':
                if ($pos == 0 || $pos == $len - 1) {
                    $result .= 'U';
                }
                break;

            case 'Y':
                if ($pos > 0 && ($next == 'A' || $next == 'U' || $next == 'O' || $next == 'E')) {
                    $result .= $next;
                    $pos++;
                } else {
                    $result .= 'Y';
                    if ($next == $c) $pos++;
                }
                break;

            case 'Z':
                $result .= 'S';
                if ($next == $c) $pos++;
                break;

            case ' ':
                $result .= ' ';
                if ($next == $c) $pos++;
                break;
        }
        $pos++;
    }

    return $result;
}