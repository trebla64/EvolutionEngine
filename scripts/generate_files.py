import csv

with open('../bin/code.csv', mode='r') as csv_file:
    csv_reader = csv.DictReader(csv_file)
    objectSet = set()
    for row in csv_reader:
        objectSet.add(row['ObjectFile'])
    for object in objectSet:
        if '.obj' in object and not ':' in object:
            f = open("./tmp/" + object.replace('.obj', '.cpp'), "w")
            f.write('#include "{0}"\n\n// TODO: Implement\n'.format(object.replace('.obj', '.h')))
            f.close()
            f = open("./tmp/" + object.replace('.obj', '.h'), "w")
            f.write('#pragma once\n\nnamespace EvolutionEngine\n{{\n\n    class {0}\n    {{\n    public:\n    }};\n\n}}\n'.format(object.replace('.obj', '')))
            f.close()
