#include "../../include/utils/menu.h"

void Menu::header()
{
    Console::clear();
    Console::divider();
    cout << "\tFootball League Simulation" << endl;
    Console::divider();
    cout << endl;
}

void Menu::main(League &league)
{
    Menu::header();
    cout << "1.Gameweeks\n"
         << "2.Standings\n"
         << "3.Statistics\n"
         << "4.Clubs Info\n"
         << "5.Players Info\n"
         << "0.exit\n"
         << "Enter your choice: ";

    bool exit_loop;
    do
    {
        exit_loop = true;
        switch (getch())
        {
        case '1':
            gameweeks(league);
            break;
        case '2':

            break;
        case '3':

            break;

        case '4':

            break;

        case '5':

            break;

        case '0':
            exit(1);

        default:
            exit_loop = false;
        }
    } while (!exit_loop);
}

void Menu::gameweeks(League &league)
{
    Menu::header();
    cout << "1.Print Gameweeks Table\n"
         << "2.Enter Gameweek #" << league.getCurrentGameweekNum() + 1 << " results\n"
         << "3.Print Gameweek #" << league.getCurrentGameweekNum() + 1 << " matches\n"
         << "0.Go back\n"
         << "Enter your choice: ";

    bool exit_loop;
    do
    {
        exit_loop = true;
        switch (getch())
        {
        case '1':
            Menu::header();
            league.printGameweeksTable();

            // go back to the gameweeks menu
            Menu::footer(league, [](League &league)
                         { gameweeks(league); });
            break;
        case '2':
            Menu::header();
            league.enterCurrGameweekResults();

            // go back to the gameweeks menu
            Menu::footer(league, [](League &league)
                         { gameweeks(league); });
            break;
        case '3':
            Menu::header();
            league.getCurrentGameweek()->printMatches();

            // go back to the gameweeks menu
            Menu::footer(league, [](League &league)
                         { gameweeks(league); });
            break;

        case '0':
            Menu::main(league);
            break;
        default:
            exit_loop = false;
        }
    } while (!exit_loop);
}

void Menu::footer(League &league, function<void(League &league)> func)
{
    cout << "Press 0 to go back\n";
    bool exit_loop;
    do
    {
        exit_loop = true;
        switch (getch())
        {
        case '0':
            func(league);
            break;
        default:
            exit_loop = false;
        }
    } while (!exit_loop);
}