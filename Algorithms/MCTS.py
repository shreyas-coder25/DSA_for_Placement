import random
import math
# Sliding Puzzle
goal = [1, 2, 3, 4, 5, 6, 7, 8, 0]

class Node:
    def __init__(self, state, parent=None):
        self.state = state
        self.parent = parent
        self.children = []
        self.visits = 0
        self.reward = 0

def moves(state):
    i = state.index(0)
    r, c = divmod(i, 3)
    result = []

    for dr, dc in [(-1,0), (1,0), (0,-1), (0,1)]:
        nr, nc = r + dr, c + dc

        if 0 <= nr < 3 and 0 <= nc < 3:
            j = nr * 3 + nc
            s = state.copy()
            s[i], s[j] = s[j], s[i]
            result.append(s)

    return result

def simulate(state):
    for _ in range(20):
        if state == goal:
            return 1

        state = random.choice(moves(state))

    return 0

def mcts(initial, iterations=100):

    root = Node(initial)

    for _ in range(iterations):

        # Selection
        node = root
        while node.children:
            node = max(node.children,
                       key=lambda n: n.reward / (n.visits + 1))
        # Expansion
        possible = moves(node.state)
        for s in possible:
            node.children.append(Node(s, node))

        if node.children:
            node = random.choice(node.children)

        # Simulation
        result = simulate(node.state)

        # Backpropagation
        while node:
            node.visits += 1
            node.reward += result
            node = node.parent
    return max(root.children, key=lambda n: n.visits).state

# Initial state
initial = [1, 2, 3,
           4, 5, 6,
           0, 7, 8]

next_state = mcts(initial)


print("Initial State:")
print(initial[:3])
print(initial[3:6])
print(initial[6:])

print("\nNext State:")
print(next_state[:3])
print(next_state[3:6])
print(next_state[6:])