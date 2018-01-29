if __name__ == '__main__':

    py = open("./resized.txt", "rb")
    c = open("./cresized.txt", "rb")

    py_all = []
    c_all = []
    for line in py.readlines():
        py_all.append(line.strip())

    for line in c.readlines():
        c_all.append(line.strip())

    for i in range(len(py_all)):
        if (int(py_all[i]) - int(c_all[i])) != 0:
            print i, ", ", py_all[i], ", ", c_all[i]
