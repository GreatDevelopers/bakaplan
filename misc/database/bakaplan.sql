-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jun 27, 2014 at 04:51 PM
-- Server version: 5.5.35
-- PHP Version: 5.4.4-14+deb7u9

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `bp_Next`
--

-- --------------------------------------------------------

--
-- Table structure for table `ClassDetail`
--

CREATE TABLE IF NOT EXISTS `ClassDetail` (
  `ClassID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `ClassName` varchar(100) NOT NULL,
  `SubjectName` varchar(200) NOT NULL,
  `SubjectCode` varchar(200) NOT NULL,
  PRIMARY KEY (`ClassID`),
  KEY `FK_ProjectID` (`ProjectID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Class or Branch details including subjects and its code' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ContactDetail`
--

CREATE TABLE IF NOT EXISTS `ContactDetail` (
  `ContactID` int(50) NOT NULL AUTO_INCREMENT,
  `Name` varchar(70) NOT NULL,
  `EmailID` varchar(100) NOT NULL,
  `Feedback` varchar(1500) NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`ContactID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Contact Form Detail or feedback form' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `DateSheet`
--

CREATE TABLE IF NOT EXISTS `DateSheet` (
  `DateSheetID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `Date` date NOT NULL,
  `SubjectCode` varchar(200) NOT NULL,
  PRIMARY KEY (`DateSheetID`),
  KEY `FK_D_ProjectID` (`ProjectID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ExamDetail`
--

CREATE TABLE IF NOT EXISTS `ExamDetail` (
  `ExamID` int(50) NOT NULL AUTO_INCREMENT,
  `DateSheetID` int(50) NOT NULL,
  `ExamName` varchar(100) NOT NULL,
  `ExamSession` varchar(50) NOT NULL,
  `ExamTime` varchar(100) NOT NULL,
  `ExamVenue` varchar(100) NOT NULL,
  PRIMARY KEY (`ExamID`),
  KEY `FK_DateSheetID` (`DateSheetID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ProjectDetail`
--

CREATE TABLE IF NOT EXISTS `ProjectDetail` (
  `ProjectID` int(50) NOT NULL AUTO_INCREMENT,
  `UserID` int(50) NOT NULL,
  `ProjectName` varchar(100) NOT NULL COMMENT 'Name of project',
  PRIMARY KEY (`ProjectID`),
  KEY `FK_ProjectDetail` (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Project Detail given by user' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Registration`
--

CREATE TABLE IF NOT EXISTS `Registration` (
  `RegID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(50) NOT NULL,
  `RegKey` varchar(100) NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`RegID`),
  UNIQUE KEY `RegID` (`RegID`,`EmailID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Registration table for BaKaPlan' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ResetPassword`
--

CREATE TABLE IF NOT EXISTS `ResetPassword` (
  `ResetID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(70) NOT NULL,
  `ResetKey` varchar(100) NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`ResetID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Rest Password Table for BaKaPlan' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `RollNoDetail`
--

CREATE TABLE IF NOT EXISTS `RollNoDetail` (
  `RollNoID` int(50) NOT NULL AUTO_INCREMENT,
  `ClassID` int(50) NOT NULL,
  `Prefix` varchar(100) NOT NULL,
  `StartRollNo` int(70) NOT NULL,
  `EndRollNo` int(70) NOT NULL,
  `NotIncluded` varchar(200) NOT NULL,
  PRIMARY KEY (`RollNoID`),
  KEY `FK_ClassID` (`ClassID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Roll No details w.r.t class id' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `RoomDetail`
--

CREATE TABLE IF NOT EXISTS `RoomDetail` (
  `RoomID` int(50) NOT NULL AUTO_INCREMENT,
  `DateSheetID` int(50) NOT NULL,
  `CentreName` varchar(200) NOT NULL,
  `RoomNo` varchar(200) NOT NULL,
  `Rows` varchar(200) NOT NULL,
  `Columns` varchar(200) NOT NULL,
  `RoomInfo` varchar(200) NOT NULL,
  PRIMARY KEY (`RoomID`),
  KEY `FK_R_DateSheetID` (`DateSheetID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `SessionDetail`
--

CREATE TABLE IF NOT EXISTS `SessionDetail` (
  `SessionID` int(50) NOT NULL AUTO_INCREMENT,
  `UserID` int(50) NOT NULL,
  `SessionKey` varchar(100) NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`SessionID`),
  KEY `UserID` (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Session Detail for BaKaPlan' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `StrategyDetail`
--

CREATE TABLE IF NOT EXISTS `StrategyDetail` (
  `StrategyID` int(50) NOT NULL AUTO_INCREMENT,
  `DateSheetID` int(50) NOT NULL,
  `StrategyNameID` int(50) NOT NULL,
  PRIMARY KEY (`StrategyID`),
  KEY `FK_S_DateSheetID` (`DateSheetID`),
  KEY `FK_StrategyNameID` (`StrategyNameID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `StrategyName`
--

CREATE TABLE IF NOT EXISTS `StrategyName` (
  `StrategyNameID` int(50) NOT NULL AUTO_INCREMENT,
  `StrategyName` varchar(100) NOT NULL,
  PRIMARY KEY (`StrategyNameID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `User`
--

CREATE TABLE IF NOT EXISTS `User` (
  `UserID` int(50) NOT NULL AUTO_INCREMENT,
  `RegID` int(50) NOT NULL,
  `Password` varchar(50) NOT NULL,
  PRIMARY KEY (`UserID`),
  KEY `RegID` (`RegID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='User Table for BaKaPlan' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ValidStrategy`
--

CREATE TABLE IF NOT EXISTS `ValidStrategy` (
  `ValidID` int(50) NOT NULL AUTO_INCREMENT,
  `StrategyID` int(50) NOT NULL,
  `DateSheetID` int(50) NOT NULL,
  `TotalSeats` int(50) NOT NULL,
  `TotalStudents` int(50) NOT NULL,
  `TotalGroupSeats` int(50) NOT NULL,
  `TotalGroupStudents` int(50) NOT NULL,
  PRIMARY KEY (`ValidID`),
  KEY `FK_V_DateSheetID` (`DateSheetID`),
  KEY `FK_V_StrategyID` (`StrategyID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `ClassDetail`
--
ALTER TABLE `ClassDetail`
  ADD CONSTRAINT `FK_ProjectID` FOREIGN KEY (`ProjectID`) REFERENCES `ProjectDetail` (`ProjectID`);

--
-- Constraints for table `DateSheet`
--
ALTER TABLE `DateSheet`
  ADD CONSTRAINT `FK_D_ProjectID` FOREIGN KEY (`ProjectID`) REFERENCES `ProjectDetail` (`ProjectID`);

--
-- Constraints for table `ExamDetail`
--
ALTER TABLE `ExamDetail`
  ADD CONSTRAINT `FK_DateSheetID` FOREIGN KEY (`DateSheetID`) REFERENCES `DateSheet` (`DateSheetID`);

--
-- Constraints for table `ProjectDetail`
--
ALTER TABLE `ProjectDetail`
  ADD CONSTRAINT `FK_ProjectDetail` FOREIGN KEY (`UserID`) REFERENCES `User` (`UserID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `RollNoDetail`
--
ALTER TABLE `RollNoDetail`
  ADD CONSTRAINT `FK_ClassID` FOREIGN KEY (`ClassID`) REFERENCES `ClassDetail` (`ClassID`);

--
-- Constraints for table `RoomDetail`
--
ALTER TABLE `RoomDetail`
  ADD CONSTRAINT `FK_R_DateSheetID` FOREIGN KEY (`DateSheetID`) REFERENCES `DateSheet` (`DateSheetID`);

--
-- Constraints for table `SessionDetail`
--
ALTER TABLE `SessionDetail`
  ADD CONSTRAINT `SessionDetail_ibfk_1` FOREIGN KEY (`UserID`) REFERENCES `User` (`UserID`);

--
-- Constraints for table `StrategyDetail`
--
ALTER TABLE `StrategyDetail`
  ADD CONSTRAINT `FK_StrategyNameID` FOREIGN KEY (`StrategyNameID`) REFERENCES `StrategyName` (`StrategyNameID`),
  ADD CONSTRAINT `FK_S_DateSheetID` FOREIGN KEY (`DateSheetID`) REFERENCES `DateSheet` (`DateSheetID`);

--
-- Constraints for table `User`
--
ALTER TABLE `User`
  ADD CONSTRAINT `User_ibfk_1` FOREIGN KEY (`RegID`) REFERENCES `Registration` (`RegID`);

--
-- Constraints for table `ValidStrategy`
--
ALTER TABLE `ValidStrategy`
  ADD CONSTRAINT `FK_V_StrategyID` FOREIGN KEY (`StrategyID`) REFERENCES `StrategyDetail` (`StrategyID`),
  ADD CONSTRAINT `FK_V_DateSheetID` FOREIGN KEY (`DateSheetID`) REFERENCES `DateSheet` (`DateSheetID`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
