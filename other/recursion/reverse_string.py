def reverse_string(text):
    if len(text) == 1:
        return text

    return reverse_string(text[1:len(text)]) + text[0]

def main():
    text = input("Enter non-empty string: ")
    if text == "":
        print("String must be non-empty")
        return
    print(reverse_string(text))

main()
