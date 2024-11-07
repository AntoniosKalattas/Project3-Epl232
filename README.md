/**
 * @mainpage Latin Square Game Automation Solver
 * 
 * @authror Antonios Kalattas
 * @author Alexandros Georgiou
 * 
 * ### Summary
 * This program processes numbers to put as default valueschemical formulas to perform various operations, such as validating parentheses,
 * expanding formulas with multiplicands, and calculating the total number of protons based on atomic numbers.
 * The project demonstrates the use of stacks, sorted structures, and dynamic memory allocation.
 * 
 * The input files include the periodic table (with element symbols and atomic numbers) and files containing chemical formulas.
 * These formulas may include nested parentheses, and the program can handle complex structures, ensuring accuracy in
 * calculations and expansion.
 * 
 * ### Program Functions
 * The program offers three main functionalities:
 * - **Validate Parentheses**: Ensures that each formula in the input file has balanced and correctly nested parentheses.
 * - **Expand Formulas**: Converts formulas with multiplicands to an expanded form.
 * - **Calculate Protons**: Calculates the total number of protons for each formula based on atomic numbers.
 * 
 * ### How to Use
 * The program is executed from the terminal with specific flags for each functionality.
 * - **Usage**: `./parseFormula periodicTable.txt -option input.txt [output.txt]`
 * - **Options**:
 *   - `-v`: Validate parentheses in the formulas.
 *   - `-ext`: Expand the formulas to a fully uncompressed form and save to `output.txt`.
 *   - `-pn`: Calculate the total protons in each formula and save to `output.txt`.
 * 
 * ### Design and Features
 * The program is designed modularly, with each main function divided into separate files for:
 * - Validating parentheses with stack operations.
 * - Expanding formulas based on symbols, multiplicands, and nested structures.
 * - Calculating protons using atomic numbers from a sorted periodic table.
 * 
 * 
 * ### Conclusion
 * This project provided valuable experience in handling dynamic data structures and file processing.
 * The program is stable, tested for edge cases, and designed for scalability. Proper memory management 
 * and modular code structure enhance its reliability and ease of use (tested for memory leaks).
 */
