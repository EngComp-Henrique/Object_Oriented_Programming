from typing import List, Set

class StateDiagram:
    
    """Represents a Deterministic finite automaton"""

    def __init__(self, all_states: Set[str], alpha: Set[str], start: str, accepted_states: Set[str]) -> None:
        """Constructs the automaton"""

        self.Q = all_states
        self.alphabet = alpha
        self.transition_function = {global_key: {inner_key: None for inner_key in alpha} for global_key in all_states}
        self.start_state = start
        self.F = accepted_states

    def delta(self, transictions: List[str]) -> bool:
        """Make the transiction function for an automaton"""

        for t in transictions:
            state_1, tr, state_2 = t.split("-")
            if state_1 in self.Q and state_2 in self.Q and tr in self.alphabet:
                self.transition_function[state_1][tr] = state_2
            else:
                return False
        return True

    def read_input(self, r_input: str) -> bool:
        """Evaluates whether a language is accepted or not in a DFA"""

        if r_input:
            current = self.start_state
            for i in r_input:
                if i in self.alphabet:
                    current = self.transition_function[current][i]
                else:
                    return False
            if current in self.F:
                return True
        return False

    def show_states(self) -> None:
        """Show all the states"""

        print("Q = {", end=" ")
        print(", ".join(self.Q), end=" ")
        print("}")

    def show_alphabet(self) -> None:
        """Show the alphabet"""

        print("\u03A3 = {", end=" ")
        print(", ".join(self.alphabet), end=" ")
        print("}")

    def show_acc_states(self) -> None:
        """Show accepted states"""

        print("F = {", end=" ")
        print(", ".join(self.F), end=" ")
        print("}")

    def show_start_state(self) -> None:
        """Show the start state"""

        print(f"The start state is \033[96m'{self.start_state}'\033[0m")
