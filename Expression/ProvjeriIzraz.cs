using System;
using System.Linq;

namespace ProvjeraTacnostiIzraza
{
    public class Program
    {
        static void Main(string[] args)
        {
            string[] izrazi = { "cos(4)cos(5)", "(1+sqrt(5))*7","s43a", "34+Sin(2)" };
            foreach (var izraz in izrazi)
            {
                Console.WriteLine(Provjeri(izraz));
            }
        }

        static bool IsItOpen(char n)
        {
            return n == '(' || n == '[' || n == '{';
        }
        static bool IsItClosed(char n)
        {
            return n == ')' || n == ']' || n == '}';
        }
        static bool IsItPair(char n1, char n2)
        {
            if (n1 == '(' && n2 == ')') return true;
            if (n1 == '[' && n2 == ']') return true;
            if (n1 == '{' && n2 == '}') return true;
            return false;
        }
        static bool isBalanced(string Array)
        {
            string newArray = "";
            for (int i = 0; i < Array.Length; i++)
            {
                if (IsItOpen(Array[i]))
                {
                    newArray += Array[i];
                }
                if (IsItClosed(Array[i]))
                {
                    if (newArray.Length != 0)
                    {
                        if (IsItPair(newArray[newArray.Length - 1], Array[i]))
                        {
                            newArray = newArray.Remove(newArray.Length - 1, 1);
                        }
                        else
                        {
                            newArray += Array[i];
                        }
                    }
                    else
                        newArray += Array[i];
                }
            }

            return newArray.Length == 0; //ako je nula return true, ako nije return false
        }
        static bool jesuLiZagradePrazne(string s)  //vazi i za izraze npr log() ako su zagrade prazne
        {
            if (s.Length != 0)
            {
                for (int i = 0; i < s.Length - 1; i++)
                {
                    if (s[i] == '(' && s[i + 1] == ')')
                        return true;
                }
            }
            return false;
        }
        static bool BiloKojiZnak(char znak)
        {
            char[] znakovi = { '+', '-', '*', '/', '=', '^', '%', '.' };
            for (int j = 0; j < 5; j++)
            {
                if (znak == znakovi[j])
                    return true;
            }
            return false;
        }
        static bool BiloKojeSlovo(char slovo)
        {
            string slova = "sctl"; //s-sin, sqrt; c-cos,ctg; t-tg; l-log,lim;
            for (int i = 0; i < slova.Length; i++)
            {
                if (slovo == slova[i])
                    return true;
            }
            return false;
        }
        static bool ZagradeSlova(string s)  //)cos  )s  
        {
            if (!s.Contains(")")) return true;
            for (int i = 0; i < s.Length - 1; i++)
            {
                if (s[i] == ')' && BiloKojeSlovo(s[i + 1]))
                    return false;
            }
            return true;
        }
        static bool ZagradeBrojevi(string s)
        {
            string brojevi = "0123456789";
            if (s.Length != 0)
            {
                for (int i = 0; i < s.Length - 1; i++)
                {
                    for (int j = 0; j < brojevi.Length; j++)
                    {
                        if (s[i] == brojevi[j] && s[i + 1] == '(')  //5(
                            return true;
                        if (s[i] == ')' && s[i + 1] == brojevi[j])    //)5
                            return true;
                    }
                }
            }
            return false;
        }

        static bool NezeljeniZnakovi(string s)
        {
            string znakovi = "!#$&?=<>;,:@|€ß";  
            if (s.Length != 0)
            {
                for (int i = 0; i < s.Length - 1; i++)
                {
                    for (int j = 0; j < znakovi.Length; j++)
                    {
                        if (s[i] == znakovi[j])
                            return true;
                    }
                }
            }
            return false;
        }
        //string moze sadrzavati funkcije sin cos...-dozvoljeno
        //string ne mora sadrzavati niti jednu funkciju-dozvoljeno
        //string moze sadrzavati slova koja su nasumicno napisana-nedozvoljeno
        //string moze sadrzavati jednu do druge funkciju npr sincos-nedozvoljeno
        //string moze sadrzavati velika slova -nedozvoljeno

        static bool FunkcijaDoFunkcije(string s)
        {
            string[] duplikati = { "sinsin", "coscos", "tgtg", "ctgctg", "loglog", "limlim", "sqtrsqtr", "lnln" };
            for (int i = 0; i < duplikati.Length; i++)
            {
                if (s.Contains(duplikati[i])) 
                    return true;
            }
            return false;
        }
        static bool isIzrazTacanSaSlovima(string s)
        {
            string[] funkcije = { "sin(", "cos(", "tg(", "ctg(", "log(", "lim(", "sqrt(", "ln(" };
            string slova = "abcdefghijklmnoprstuvzwqxy";
            int brojac = 0, brojacVelikihSlova = 0; 

            for (int i = 0; i < slova.Length; i++)
            {
                if (s.Contains(slova.ToUpper()[i]))
                    brojacVelikihSlova++;
                for (int m=0; m<funkcije.Length; m++)
                {                   
                    if (!s.Contains(slova[i]) && !s.Contains(funkcije[m]))
                        brojac++;
                    if (s.Contains(slova[i]) && !s.Contains(funkcije[m]))
                        return false;
                    if (s.Contains(funkcije[m])) return true;
                }
            }
            if ((brojacVelikihSlova == 0 || brojac == slova.Length+funkcije.Length)) return true;
            return false;
        }
        static bool is_correct_expression(string s)
        {
            if (s.Length != 0)
            {
                if (BiloKojiZnak(s[0]) && s[0] != '-')
                    return false;
                if (BiloKojiZnak(s[s.Length - 1]) && s[s.Length - 1] != '%')
                    return false;

                for (int i = 0; i < s.Length - 1; i++)
                {
                    if (BiloKojiZnak(s[i]) && s[i] != '%' && BiloKojiZnak(s[i + 1]))
                        return false;
                    if (BiloKojiZnak(s[i]) && BiloKojiZnak(s[i + 1]) && s[i] == s[i + 1])
                        return false;
                    if (BiloKojiZnak(s[i]) && s[i + 1] == ')')
                        return false;
                    if (s[i] == '(' && BiloKojiZnak(s[i + 1]))
                        return false;
                }
            }
            return true;
        }

        static string Provjeri(string s)
        {
            if (!jesuLiZagradePrazne(s) && isBalanced(s) && isIzrazTacanSaSlovima(s) &&
               !FunkcijaDoFunkcije(s) && !NezeljeniZnakovi(s) && !ZagradeBrojevi(s) &&
                ZagradeSlova(s) && is_correct_expression(s))
            {
                return "Izraz je tacno napisan.";
            }
            else
            {
                return "Izraz nije tacno napisan.";
            }
        }
    }
}
