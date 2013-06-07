-- phpMyAdmin SQL Dump
-- version 3.4.10.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: May 22, 2013 at 08:41 AM
-- Server version: 5.5.31
-- PHP Version: 5.3.10-1ubuntu3.6

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `mandeep`
--

-- --------------------------------------------------------

--
-- Table structure for table `ClassDetail`
--

CREATE TABLE IF NOT EXISTS `ClassDetail` (
  `ClassID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `ClassName` varchar(50) NOT NULL,
  `SubjectName` varchar(150) NOT NULL,
  `SubjectCode` varchar(100) NOT NULL,
  PRIMARY KEY (`ClassID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `DateSheet`
--

CREATE TABLE IF NOT EXISTS `DateSheet` (
  `DateSheetID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `Date` date NOT NULL,
  `ExamCode` varchar(70) NOT NULL,
  PRIMARY KEY (`DateSheetID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ExamDetail`
--

CREATE TABLE IF NOT EXISTS `ExamDetail` (
  `ExamID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `DateSheetID` int(50) NOT NULL,
  `ExamName` varchar(70) NOT NULL,
  `ExamSession` varchar(50) NOT NULL,
  `ExamTime` varchar(50) NOT NULL,
  `ExamVenue` varchar(70) NOT NULL,
  PRIMARY KEY (`ExamID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ProjectDetail`
--

CREATE TABLE IF NOT EXISTS `ProjectDetail` (
  `ProjectID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(50) NOT NULL,
  `ProjectName` varchar(70) NOT NULL,
  PRIMARY KEY (`ProjectID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Registeration`
--

CREATE TABLE IF NOT EXISTS `Registeration` (
  `RegistrationID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(30) NOT NULL,
  `RegistrationKey` varchar(70) NOT NULL,
  PRIMARY KEY (`EmailID`),
  UNIQUE KEY `RegisterationID` (`RegistrationID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ResetPassword`
--

CREATE TABLE IF NOT EXISTS `ResetPassword` (
  `PassKey` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(70) NOT NULL,
  `ResetKey` varchar(100) NOT NULL,
  PRIMARY KEY (`PassKey`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `RollNoDetail`
--

CREATE TABLE IF NOT EXISTS `RollNoDetail` (
  `RollNoID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `ClassID` int(50) NOT NULL,
  `Prefix` varchar(50) NOT NULL,
  `StartRollNo` int(50) NOT NULL,
  `EndRollNo` int(50) NOT NULL,
  `NotIncluded` varchar(70) NOT NULL,
  PRIMARY KEY (`RollNoID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `RoomDetail`
--

CREATE TABLE IF NOT EXISTS `RoomDetail` (
  `RoomID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `DateSheetID` int(50) NOT NULL,
  `CentreName` varchar(50) NOT NULL,
  `RoomInfo` varchar(150) NOT NULL,
  `RoomNo` varchar(50) NOT NULL,
  `Rows` varchar(50) NOT NULL,
  `Columns` varchar(50) NOT NULL,
  PRIMARY KEY (`RoomID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `SessionDetail`
--

CREATE TABLE IF NOT EXISTS `SessionDetail` (
  `SessionID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(70) NOT NULL,
  `SessionKey` varchar(100) NOT NULL,
  PRIMARY KEY (`SessionID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `StrategyDetail`
--

CREATE TABLE IF NOT EXISTS `StrategyDetail` (
  `StrategyID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `StrategyName` varchar(50) NOT NULL,
  `DateSheetID` int(50) NOT NULL,
  PRIMARY KEY (`StrategyID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `User`
--

CREATE TABLE IF NOT EXISTS `User` (
  `UserID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(30) NOT NULL,
  `Password` varchar(70) NOT NULL,
  PRIMARY KEY (`EmailID`),
  UNIQUE KEY `UserID` (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ValidStrategy`
--

CREATE TABLE IF NOT EXISTS `ValidStrategy` (
  `ValidID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `DateID` int(50) NOT NULL,
  `Date` varchar(50) NOT NULL,
  `SelectedStrategy` varchar(50) NOT NULL,
  `TotalSeats` int(50) NOT NULL,
  `TotalStudents` int(50) NOT NULL,
  `TotalGroupSeats` int(50) NOT NULL,
  `TotalGroupStudents` int(50) NOT NULL,
  PRIMARY KEY (`ValidID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
