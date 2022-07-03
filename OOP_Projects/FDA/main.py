from state_diagram import StateDiagram
import os
import time

def line() -> None:
    """Write a line"""

    print("-" * 60)

def main() -> None:
    """Main function"""

    DFA = StateDiagram(set(['s', 'q1', 'q2', 'r1', 'r2']), set(['a', 'b']), 's', set(['q1', 'r1']))
    DFA.delta(
        [
            's-a-q1',
            's-b-r1',
            'q1-a-q1',
            'q1-b-q2',
            'q2-a-q1',
            'q2-b-q2',
            'r1-b-r1',
            'r1-a-r2',
            'r2-b-r1',
            'r2-a-r2'
        ]
    )

    while True:
        print("\033[1m\033[95mTESTING DETERMINISTIC FINITE AUTOMATON\033[0m\033[0m\n")
        print("AUTOMATON DESCRIPTION:")
        DFA.show_states()
        DFA.show_alphabet()
        DFA.show_acc_states()
        DFA.show_start_state()
        line()
        i = input("Type your input: \033[33m") 
        print("\033[0m", end="")
        line()
        r = DFA.read_input(i)
        if r:
            print(f"The input \033[33m{i}\033[0m was \033[92m accepted\033[0m")
        else:
            print(f"The input \033[33m{i}\033[0m was \033[31mrejected\033[0m")
        print("Press enter to continue")
        i = input()
        time.sleep(0.75)
        os.system("clear")

if __name__ == "__main__":
    main()
