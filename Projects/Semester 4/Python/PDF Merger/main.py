import PyPDF2
import os

pdffiles = []
n = int(input("Enter the number of pdf files you want to merge: "))
for i in range(n):
    file = input(f"Enter the path of the pdf file {i+1}: ")
    pdffiles.append(file)

output = input("Enter the path where you want to save the merged pdf file: ")

merger = PyPDF2.PdfMerger()
for file in pdffiles:
    pdf = open(file, 'rb')
    pdfReader = PyPDF2.PdfReader(pdf)
    merger.append(pdfReader)

pdf.close()
merger.write(output)
merger.close()

print("PDF files merged successfully!")
os.startfile(output)

