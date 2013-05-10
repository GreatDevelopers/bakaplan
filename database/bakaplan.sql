-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Mar 17, 2013 at 01:52 PM
-- Server version: 5.5.28
-- PHP Version: 5.4.6-1ubuntu1.1

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `bakaplan`
--

-- --------------------------------------------------------

--
-- Table structure for table `ClassDetails`
--

CREATE TABLE IF NOT EXISTS `ClassDetails` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `ClassName` varchar(50) NOT NULL,
  `TotalSubjects` int(50) NOT NULL,
  `SubjectName` varchar(100) NOT NULL,
  `SubjectCode` varchar(100) NOT NULL,
  UNIQUE KEY `SNo` (`SNo`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=44 ;

--
-- Dumping data for table `ClassDetails`
--

INSERT INTO `ClassDetails` (`SNo`, `ProjectID`, `ClassName`, `TotalSubjects`, `SubjectName`, `SubjectCode`) VALUES
(9, 1, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(10, 1, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(11, 3, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(12, 3, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(13, 3, 'ECE', 2, 'OS, EVS', 'EVS, ED-10'),
(14, 3, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(15, 3, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(16, 3, 'ECE', 2, 'OS, EVS', 'EVS, ED-10'),
(17, 3, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(18, 3, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(19, 3, 'ECE', 2, 'OS, EVS', 'EVS, ED-10'),
(20, 3, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(21, 3, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(22, 3, 'ECE', 2, 'OS, EVS', 'EVS, ED-10'),
(23, 3, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(24, 3, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(25, 3, 'ECE', 2, 'OS, EVS', 'EVS, ED-10'),
(26, 3, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(27, 3, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(28, 3, 'ECE', 2, 'OS, EVS', 'EVS, ED-10'),
(29, 3, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(30, 3, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(31, 3, 'ECE', 2, 'OS, EVS', 'EVS, ED-10'),
(32, 4, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(33, 4, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(34, 6, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(35, 6, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(36, 6, 'ECE', 2, 'OS, EVS', 'EVS, ED-10'),
(37, 6, 'Mech. Engg.', 2, 'Java, C++', 'ED-10, IT-102'),
(38, 6, 'Production Engg.', 1, 'EVS', 'IT-102'),
(39, 7, 'Info. Tech.', 2, 'DBMS, SAD', 'IT-101, IT-102'),
(40, 7, '10th', 2, 'Maths,Physics', 'ME-10,CE-252'),
(41, 7, 'ECE', 2, 'OS, EVS', 'EVS, ED-10'),
(42, 7, 'Mech. Engg.', 2, 'Java, C++', 'ED-10, IT-102'),
(43, 7, 'Production Engg.', 1, 'EVS', 'IT-102');

-- --------------------------------------------------------

--
-- Table structure for table `ExamDetail`
--

CREATE TABLE IF NOT EXISTS `ExamDetail` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `ExamName` varchar(100) NOT NULL,
  `ExamDate` varchar(100) NOT NULL,
  `ExamTime` varchar(100) NOT NULL,
  `ExamVenue` varchar(100) NOT NULL,
  KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ProjectName`
--

CREATE TABLE IF NOT EXISTS `ProjectName` (
  `ProjectID` int(100) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(50) NOT NULL,
  `ProjectName` varchar(30) NOT NULL,
  PRIMARY KEY (`ProjectID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Dumping data for table `ProjectName`
--

INSERT INTO `ProjectName` (`ProjectID`, `EmailID`, `ProjectName`) VALUES
(1, 'mandy@gmail.com', 'first project'),
(2, 'mandy@gmail.com', 'first project'),
(3, 'mandy@gmail.com', 'Project 1'),
(4, 'mandy@gmail.com', 'Project Name'),
(5, 'mandy@gmail.com', 'Project Name'),
(6, 'mandy@gmail.com', 'Project Name'),
(7, 'mandy@gmail.com', 'Project Name');

-- --------------------------------------------------------

--
-- Table structure for table `RollNoDetail`
--

CREATE TABLE IF NOT EXISTS `RollNoDetail` (
  `ProjectID` int(100) NOT NULL,
  `ClassName` varchar(50) NOT NULL,
  `SubjectCode` varchar(30) NOT NULL,
  `Prefix` varchar(30) NOT NULL,
  `StartRollNo` int(50) NOT NULL,
  `EndRollNo` int(50) NOT NULL,
  `NotIncluded` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `RollNoDetail`
--

INSERT INTO `RollNoDetail` (`ProjectID`, `ClassName`, `SubjectCode`, `Prefix`, `StartRollNo`, `EndRollNo`, `NotIncluded`) VALUES
(4, 'Info. Tech.', 'IT-101', 'dcdec', 101, 120, '111 120'),
(4, 'Info. Tech.', ' IT-102', '901', 101, 111, '121'),
(4, '10th', 'ME-10', '11', 111, 112, '1'),
(4, '10th', 'CE-252', '11', 123, 134, '122'),
(4, 'Info. Tech.', 'IT-101', 'dcdec', 101, 120, '111 120'),
(4, 'Info. Tech.', ' IT-102', '901', 101, 111, '121'),
(4, '10th', 'ME-10', '11', 111, 112, '1'),
(4, '10th', 'CE-252', '11', 123, 134, '122'),
(6, 'Info. Tech.', 'IT-101', 'IT', 101, 121, '111 120'),
(6, 'Info. Tech.', 'IT-101', 'IT', 101, 121, '111 120'),
(6, 'Info. Tech.', 'IT-101', 'IT', 101, 121, '111 120'),
(6, 'Info. Tech.', 'IT-101', 'IT', 101, 121, '111 120');

-- --------------------------------------------------------

--
-- Table structure for table `RoomDetail`
--

CREATE TABLE IF NOT EXISTS `RoomDetail` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `CentreName` varchar(100) NOT NULL,
  `RoomNo` varchar(100) NOT NULL,
  `Rows` int(30) NOT NULL,
  `Columns` int(30) NOT NULL,
  UNIQUE KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Session`
--

CREATE TABLE IF NOT EXISTS `Session` (
  `SNo` int(25) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(150) NOT NULL,
  `SessionID` varchar(250) NOT NULL,
  PRIMARY KEY (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Strategy`
--

CREATE TABLE IF NOT EXISTS `Strategy` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `StrategyName` varchar(100) NOT NULL,
  PRIMARY KEY (`ProjectID`),
  UNIQUE KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `TotalCentres`
--

CREATE TABLE IF NOT EXISTS `TotalCentres` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `TotalCentres` int(50) NOT NULL,
  KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `TotalClasses`
--

CREATE TABLE IF NOT EXISTS `TotalClasses` (
  `ProjectID` int(255) NOT NULL,
  `TotalClasses` int(30) NOT NULL,
  PRIMARY KEY (`ProjectID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `TotalClasses`
--

INSERT INTO `TotalClasses` (`ProjectID`, `TotalClasses`) VALUES
(1, 2),
(2, 3),
(3, 3),
(4, 2),
(5, 3),
(6, 5),
(7, 5);

-- --------------------------------------------------------

--
-- Table structure for table `TotalRooms`
--

CREATE TABLE IF NOT EXISTS `TotalRooms` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `CentreName` varchar(100) NOT NULL,
  `TotalRooms` int(70) NOT NULL,
  KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `User`
--

CREATE TABLE IF NOT EXISTS `User` (
  `SNo` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(30) NOT NULL,
  `Password` varchar(250) NOT NULL,
  PRIMARY KEY (`EmailID`),
  KEY `SNo` (`SNo`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Dumping data for table `User`
--

INSERT INTO `User` (`SNo`, `EmailID`, `Password`) VALUES
(8, 'abc@123.com', 'e10adc3949ba59abbe56e057f20f883e'),
(7, 'mandeep@gmail.com', '202cb962ac59075b964b07152d234b70'),
(9, 'mandy@gmail.com', '81dc9bdb52d04dc20036dbd8313ed055');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
