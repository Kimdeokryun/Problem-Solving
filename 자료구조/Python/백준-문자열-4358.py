from sys import stdin

def main():

    species_dict = {}
    count = 0
    while True:
        species = stdin.readline().strip()
        if species == "":
            break

        count += 1
        if species in species_dict:
            species_dict[species] += 1
        else:
            species_dict[species] = 1

    sorted_key = sorted(species_dict.keys())

    for key in sorted_key:
        print("%s %.4f" % (key, species_dict[key] / count * 100))


if __name__ == "__main__":
    main()